#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include "Colors.hpp"

class WrongAnimal {

	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& ref);
		WrongAnimal&	operator=(const WrongAnimal& ref);
		virtual				~WrongAnimal();
		std::string		getType() const ;
		void	makeSound() const ;

	protected:
		std::string	type;
};

#endif