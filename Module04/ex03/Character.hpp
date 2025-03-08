#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {

	private:
		std::string	name;
		AMateria* slots[4];

	public:
		Character();
		Character(std::string _name);
		Character(const Character& copy);
		Character&	operator=(const Character& ref);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria const*	getMateria(int idx);
};

#endif