#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "Colors.hpp"
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

	protected:
		std::string	type;

	public:
	AMateria();
	AMateria(const AMateria& copy);
	AMateria(std::string const & type);
	AMateria& operator=(const AMateria& ref);
	virtual ~AMateria();
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif