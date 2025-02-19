#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string name ) : name(name) {}

void	Zombie::annonce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string newName) { name = newName; }