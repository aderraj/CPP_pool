#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "Shrubberry Form constructor created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other) {

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery Form destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) {
	
}