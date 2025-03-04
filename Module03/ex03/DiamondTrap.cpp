#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), Name("default") {
	HitPoints = FragTrap::HitPoints;
	AttackDamage = FragTrap::AttackDamage;
	EnergyPoints = 50;
	std::cout << BOLD MAGENTA "DiamondTrap's " RESET
						<< "default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), Name(name) {
	HitPoints = FragTrap::HitPoints;
	AttackDamage = FragTrap::AttackDamage;
	EnergyPoints = 50;
	std::cout << BOLD MAGENTA "DiamondTrap's " RESET
						<< GREEN "constructor called." RESET << std::endl;
 }

DiamondTrap::DiamondTrap(const DiamondTrap& ref)
	: ClapTrap(ref), ScavTrap(ref), FragTrap(ref) { }

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& ref) {
	if (this != &ref) {
		ClapTrap::operator=(ref);
		Name = ref.Name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << BOLD MAGENTA "DiamondTrap's " RESET
						<< RED "destructor called." RESET << std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout << "I am " << Name << " formely " << ClapTrap::Name << std::endl;
}