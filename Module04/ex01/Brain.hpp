#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {

	public:
		Brain();
		Brain(const Brain& copy);
		Brain&	operator=(const Brain& ref);
		~Brain();
		std::string	ideas[100];

};

#endif