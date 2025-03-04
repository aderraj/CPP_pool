#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << BOLD BRIGHT_BLUE "FragTrap's " RESET
						<< "default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << BOLD BRIGHT_BLUE "FragTrap's " RESET
						<< GREEN "constructor called." RESET
						<< std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref) {
	std::cout << "FragTrap's copy constructor called." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& ref) {
	if (this != &ref)
		ClapTrap::operator=(ref);
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << BOLD BRIGHT_BLUE "FragTrap's " RESET
						<< RED "destructor called." RESET << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << CYAN << Name << RESET
						" requests a positive high five!" << std::endl;
}