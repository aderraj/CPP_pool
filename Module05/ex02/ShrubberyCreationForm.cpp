#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target(NULL) {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target) :
	AForm("ShrubberyCreationForm", 145, 137), target(_target) {
	std::cout << "Shrubberry Form constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other) , target(other.target) {
	std::cout << "Shrubberry Form copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	this->target = other.target;
	std::cout << "Shrubberry Form operator= called " << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery Form destructor called" << std::endl;
}

void	ShrubberyCreationForm::executeAction() const {
  std::fstream file((target + "_shrubbery").c_str());
	file << "ascii tree\n";
	file.close();
}