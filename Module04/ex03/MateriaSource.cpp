#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	for (int i = 0; i < 4; i++){
		if (copy.inventory[i] != NULL)
			inventory[i] = copy.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& ref) {
	if (this != &ref) {
		for (int i = 0; i < 4; i++) {
			delete inventory[i];
			if (ref.inventory[i] != NULL)
				inventory[i] = ref.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		delete inventory[i];
	std::cout << "MateriaSource's destructor called." << std::endl;
}

void	MateriaSource::learnMateria(AMateria* m) {
	int	i;

	if (!m) {
		std::cout << "Cannot learn invalid materia!" << std::endl;
		return ;
	}
	for (i = 0; i < 4; i++) {
		if (inventory[i] == NULL) {
			inventory[i] = m;
			std::cout << "Materia " << inventory[i]->getType() << " learned." << std::endl;
			break;
		}
	}
	if (i == 4)
		std::cout << "Cannot learn more than 4 Materias!" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	if (type.empty()) {
		std::cout << "cannot create Materia with invalid type!";
		return (NULL);
	}

	for (int i = 0; i < 4; i++) {
		if (inventory[i] && inventory[i]->getType() == type) {
			return (inventory[i]->clone());
		}
	}
	std::cout << "Unknown Materia type!" << std::endl;
	return (NULL);
}
