#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& copy) : AMateria(copy) {}

Ice&	Ice::operator=(const Ice& ref) {
	if (this != &ref)
		AMateria::operator=(ref);
	return (*this);
}

Ice::~Ice() {
	std::cout << "Ice's destructor called." << std::endl;
}

AMateria*	Ice::clone() const {
	return ( new Ice() );
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at "
						<< target.getName() << "*"
						<< std::endl;
}