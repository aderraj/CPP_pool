#include "Form.hpp"
#include <iostream>

Form::Form() :
							name("default"),
							_signed(false),
							signGrade(150),
							execGrade(150) {
	std::cout << YELLOW "Form's default"
							 "constructor called."
							 RESET << std::endl;
}

Form::Form(std::string _name, short _signGrade, short _execGrade) :
				name(_name),
				_signed(false),
				signGrade(_signGrade),
				execGrade(_execGrade) {
	std::cout << YELLOW "Form's" GREEN
							 " constructor called."
							 RESET << std::endl;
}

Form::Form(const Form& other) :
			name(other.name),
			_signed(other._signed),
			signGrade(other.signGrade),
			execGrade(other.execGrade)
{
	std::cout << YELLOW "Form's" BOLD
							" cpy constructor called."
							 RESET << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

Form::~Form() {
		std::cout << YELLOW "Form's" RED
							" destructor called."
							 RESET << std::endl;
}

const std::string&	Form::getName() const { return (name); }

const bool&					Form::getSign() const { return (_signed); }

const short&				Form::getSignGrade() const { return (signGrade); }

const short&				Form::getExecGrade() const { return (execGrade); }

std::ostream&	operator<<(std::ostream& out, Form& form) {
	out << form.getName() << " is "
			<< (form.getSign() ? "signed" : "not signed")
			<< " with sign grade: " << form.getSignGrade()
			<< " & execute grade: " << form.getExecGrade();
	return (out);
}


void	Form::beSigned(Bureaucrat& owner) {
	if (owner.getGrade() > signGrade)
		throw (Bureaucrat::GradeTooLowException());

	_signed = true;
	std::cout << "Form : " << name
						<< " signed succesfully" << std::endl;
}