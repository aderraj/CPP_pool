#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Colors.hpp"

class Animal {

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& ref);
		Animal&	operator=(const Animal& ref);
		virtual ~Animal();
		std::string		getType() const ;
		virtual void	makeSound() const ;

	protected:
		std::string	type;
};

#endif