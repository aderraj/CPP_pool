#include "AMateria.hpp"

AMateria::AMateria() : type("Raw") { }

AMateria::AMateria(const AMateria& copy) : type(copy.type) { }

AMateria& AMateria::operator=(const AMateria& ref) {
	return ((void)ref, (*this));
}

AMateria::~AMateria() { }

AMateria::AMateria(std::string const & type) : type(type) { }

std::string const& AMateria::getType() const { return (type); }

void AMateria::use(ICharacter& target) {
	std::cout << "Materia used at target " << target.getName()
						<< std::endl;
}