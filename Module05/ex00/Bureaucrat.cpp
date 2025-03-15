#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(0) {
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, short _grade) 
	throw(GradeTooHighException&, GradeTooLowException&) : 
		name(_name), grade(_grade) {
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
						name(other.name), grade(other.grade) {
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called." << std::endl;
}

const std::string&	Bureaucrat::getName() const { return (name); }

short	Bureaucrat::getGrade() const { return (grade); }

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