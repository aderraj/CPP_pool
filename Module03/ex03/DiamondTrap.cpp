#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), Name(name) {
	HitPoints = FragTrap::HitPoints;
	AttackDamage = FragTrap::AttackDamage;
	EnergyPoints = ScavTrap::EnergyPoints;
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

DiamondTrap::~DiamondTrap() { std::cout << "Diamond Trap destructor called" <<  std::endl; }

void	DiamondTrap::whoAmI() {
	std::cout << "I am " << Name << " formely " << ClapTrap::Name << std::endl;
}