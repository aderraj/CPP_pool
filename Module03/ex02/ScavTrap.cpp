#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap's default constructor called." << std::endl; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap's constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref) {
	std::cout << "ScavTrap's copy constructor called." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& ref) {
	if (this != &ref)
		ClapTrap::operator=(ref);
	return (*this);
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap's destructor called." << std::endl; }

void	ScavTrap::attack(const std::string& target) {
	if (EnergyPoints > 0 && HitPoints > 0) {
		std::cout << "ScavTrap " << Name << " attacks " << target
							<< " , causing " << AttackDamage
							<< " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else
		std::cout << "ScavTrap " << Name
		<< " has no Points to attack!" << std::endl;
}
void	ScavTrap::guardGate( void ) { 
	std::cout << "ScavTrap " << Name << " is now in Gate keeper mode" << std::endl;
}
