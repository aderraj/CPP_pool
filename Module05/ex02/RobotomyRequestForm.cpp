#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), target(NULL) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string _target) : AForm("Robotomy", 72, 45), target(_target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	this->target = other.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::executeAction() const {
	std::cout << "Bzzt..rrrrt...dsss..zzz" << std::endl;
	std::srand(std::time(0));
	if (rand() % 2)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}

