#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), target(NULL) {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string _target) : AForm("Robotomy", 72, 45), target(_target) { 
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {
	std::cout << "RobotomyRequestFrom copy constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	this->target = other.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::executeAction() const {
	std::cout << "Bzzt..rrrrt...dsss..zzz" << std::endl;
	std::srand(std::time(0));
	if (rand() % 2)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << target << " the robotomy failed" << std::endl;
}

