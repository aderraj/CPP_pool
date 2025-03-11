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

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
	if (other.grade > 150)
		throw GradeTooLowException();
	else if (other.grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		grade = other.grade;
		if (other.grade > 150)
		throw GradeTooLowException();
	else if (other.grade < 1)
		throw GradeTooHighException();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called." << std::endl;
}

const std::string&	Bureaucrat::getName() { return (name); }

short	Bureaucrat::getGrade() { return (grade); }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}