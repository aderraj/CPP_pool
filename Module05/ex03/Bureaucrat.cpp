#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(0) {}

Bureaucrat::Bureaucrat(std::string _name, short _grade) 
	throw(GradeTooHighException&, GradeTooLowException&) : 
		name(_name), grade(_grade) {
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException(); }

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
						name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string&	Bureaucrat::getName() const { return (name); }

const short&	Bureaucrat::getGrade() const { return (grade); }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return RED "Grade is too" BOLD " HIGH!" RESET ;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return RED "Grade is too" BOLD " low!" RESET;
}

void	Bureaucrat::incrementGrade() {
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void	Bureaucrat::decrementGrade() {
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& ref) {
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade()
	<< std::endl;
	return (out);
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << "Bureaucrat " << name
							<< GREEN " signed" << RESET " form "
              << form.getName() << std::endl; 
	} catch (std::exception& e) {
		std::cout << "Bureaucrat " << name
							<< RED " couldn't sign form " << form.getName() 
							<< ": grade is too" BOLD " low!" RESET << std::endl; 
	}
}


void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << name << CYAN " executed " RESET << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name << " couldn't execute Form : "
							<< e.what() << std::endl;
	}
}