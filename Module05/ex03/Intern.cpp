#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern&	Intern::operator=(const Intern& other) { return ((void)other, *this); }

Intern::~Intern() {}

AForm*  makeRobotomyForm(const std::string& target) {
  return new RobotomyRequestForm(target);
}

AForm*  makePresidentialForm(const std::string& target) {
  return new PresidentialPardonForm(target);
}
AForm*  makeShrubberyForm(const std::string& target) {
  return new ShrubberyCreationForm(target);
}

AForm*	 Intern::makeForm(std::string name, std::string _target) {
  t_indexedForm forms[] = {
    {"robotomy request", &makeRobotomyForm},
    {"presidential pardon", &makePresidentialForm},
    {"shrubbery creation", &makeShrubberyForm},
  };

  for (int i = 0; name[i]; i++)
    name[i] = tolower(name[i]);

  for (int i = 0; i < 3; i++) {
    if (name == forms[i].name) {
      std::cout << "Intern creates " << forms[i].name << std::endl;
      return forms[i].f(_target);
    }
  }
  std::cout << YELLOW "Intern can't create unkown Form" RESET << std::endl;
  return NULL;
}