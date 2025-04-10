#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidental", 25, 5) , target(NULL) {
	std::cout << "PresidentalPardon default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string _target) : AForm("Presidental", 25, 5), target(_target) {
	std::cout << "PresidentalPardon constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) {
	std::cout << "Presidental copy constructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	this->target = other.target;
	return (*this);
}

void PresidentialPardonForm::executeAction() const{
	std::cout << target << " has been pardoned by Zaphod BeebleBrox" << std::endl;
}