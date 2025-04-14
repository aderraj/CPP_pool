#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidental", 25, 5) , target(NULL) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string _target) : AForm("Presidental", 25, 5), target(_target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	this->target = other.target;
	return (*this);
}

void PresidentialPardonForm::executeAction() const{
	std::cout << target << " has been pardoned by Zaphod BeebleBrox" << std::endl;
}