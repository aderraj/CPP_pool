#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
											AForm("Shrubbery", 145, 137),
											target(NULL) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target) :
											AForm("Shrubbery", 145, 137),
											target(_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other) , target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	this->target = other.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::executeAction() const {
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file) {
		std::cerr << "Error: Could not create a file" << std::endl;
		return ;
	}
	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\\\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\\\n";
	file.close();
}