#include "AForm.hpp"
#include <iostream>

AForm::AForm() :
							name("default"),
							_signed(false),
							signGrade(150),
							execGrade(150) {}

AForm::AForm(std::string _name, short _signGrade, short _execGrade) :
				name(_name),
				_signed(false),
				signGrade(_signGrade),
				execGrade(_execGrade) {}

AForm::AForm(const AForm& other) :
			name(other.name),
			_signed(other._signed),
			signGrade(other.signGrade),
			execGrade(other.execGrade) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

AForm::~AForm() {}

const std::string&	AForm::getName() const { return (name); }

const bool&					AForm::getSign() const { return (_signed); }

const short&				AForm::getSignGrade() const { return (signGrade); }

const short&				AForm::getExecGrade() const { return (execGrade); }

std::ostream&	operator<<(std::ostream& out, AForm& form) {
	out << form.getName() << " is "
			<< (form.getSign() ? "signed" : "not signed")
			<< " with sign grade: " << form.getSignGrade()
			<< " & execute grade: " << form.getExecGrade();
	return (out);
}


void	AForm::beSigned(Bureaucrat& owner) {
	if (owner.getGrade() > signGrade)
		throw (Bureaucrat::GradeTooLowException());

	_signed = true;
}

void	AForm::execute(const Bureaucrat& executor) const {
 	if (!_signed)
		throw FormNotSignedException();
	else if (executor.getGrade() > execGrade)
		throw Bureaucrat::GradeTooLowException();
	this->executeAction();
}

const char* AForm::FormNotSignedException::what() const throw(){
	return (RED "Form not signed!" RESET);
}