#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap constructor called" << std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& ref) {
	if (this != &ref) {
		ClapTrap::operator=(ref);
	}
	return (*this);
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

void	ScavTrap::attack(const std::string& target) {
	if (EnergyPoints > 0 && HitPoints > 0) {
		std::cout << "ScavTrap " << Name << " attacks " << target
							<< " , causing " << AttackDamage
							<< " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else
		std::cout << "ScavTrap " << Name\
		<< " has no Points to attack!" << std::endl;
}

void	ScavTrap::guardGate( void ) { 
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
