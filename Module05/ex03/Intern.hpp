#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {

	public:
		Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();
		AForm*	makeForm(std::string name, std::string _target);
};

typedef struct s_indexedForm{
  std::string name;
  AForm*	(*f)(const std::string&);
} t_indexedForm;

#endif