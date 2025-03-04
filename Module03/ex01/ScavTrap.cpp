#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << BOLD BRIGHT_GREEN "ScavTrap's " RESET
						<< "default constructor called." << std::endl; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << BOLD BRIGHT_GREEN "ScavTrap's " RESET
						GREEN "constructor called." RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref) {
	std::cout << BOLD BRIGHT_GREEN "ScavTrap's " RESET
						<< BRIGHT_GREEN "ScavTrap's copy constructor called."
						RESET << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& ref) {
	if (this != &ref)
		ClapTrap::operator=(ref);
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << BOLD BRIGHT_GREEN "ScavTrap's " RESET
						<< RED "destructor called." << std::endl; }

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
	std::cout << BOLD BRIGHT_GREEN "ScavTrap " RESET
						<< Name << BLUE " is now in Gate keeper mode"
						RESET << std::endl;
}
