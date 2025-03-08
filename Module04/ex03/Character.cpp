#include "Character.hpp"

Character::Character() : ICharacter() , name("default") {
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::Character(std::string _name) : ICharacter() , name(_name) {
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::Character(const Character& copy) : name(copy.name) {
	for (int i = 0; i < 4; i++) {
		if (copy.slots[i] != NULL)
			slots[i] = copy.slots[i]->clone();
	}
}


Character&	Character::operator=(const Character& ref) {
	if (this != &ref) {
		name = ref.name;
		for (int i = 0; i < 4; i++) {
			delete slots[i];
			if (ref.slots[i] != NULL)
				slots[i] = ref.slots[i]->clone();
			else
				slots[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete slots[i];
		slots[i] = NULL;
	}
}

std::string const&	Character::getName() const { return (name); }

AMateria const*	Character::getMateria(int idx) { return (slots[idx]); }

void	Character::equip(AMateria* m) {

	int	i;

	if (m == NULL) {
		std::cout << "cannot equip invalid Materia!" << std::endl;
		return ;
	}

	for (i = 0; i < 4; i++) {
		if (slots[i] == NULL) {
			slots[i] = m;
			break;
		}
	}
	if (i == 4) 
		std::cout << "No more slots to equip!" << std::endl;
}

void	Character::unequip(int idx) {

	if (idx < 0 || idx > 3) {
		std::cout << "cannot unequip Materia at invalid idx!" << std::endl;
		return ;
	}

	if (slots[idx] != NULL)
		slots[idx] = NULL;
	else
		std::cout << "cannot unequip Materia at empty slot!" << std::endl;

}

void	Character::use(int idx, ICharacter& target) {

	if (idx < 0 || idx > 3) {
		std::cout << "cannot use Materia at invalid idx!" << std::endl;
		return ;
	}

	if (slots[idx] != NULL)
		slots[idx]->use(target);
	else
			std::cout << "no Materia to use at this idx!" << std::endl;

}
