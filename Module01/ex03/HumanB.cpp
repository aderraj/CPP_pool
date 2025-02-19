#include "HumanB.hpp"

HumanB::HumanB( std::string _name ) : name(_name) , weapon(NULL) {}

void	HumanB::setWeapon( Weapon& new_w ) { weapon = &new_w; }

void	HumanB::attack( void ) {
	
	std::cout << name << " attacks with their "\
	<< (weapon ? weapon->getType() : "null") << std::endl;
}