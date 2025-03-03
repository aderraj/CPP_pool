#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Name("default_name"), HitPoints(10),
											EnergyPoints(10), AttackDamage(0) {
	std::cout << "ClapTrap's default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name),
					HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << "ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref) : Name(ref.Name),
					HitPoints(ref.HitPoints), EnergyPoints(ref.EnergyPoints),
					AttackDamage(ref.AttackDamage) {
	std::cout << "ClapTrap's copy constructor called." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& ref) {
	if (this != &ref) {
		Name = ref.Name;
		HitPoints = ref.HitPoints;
		EnergyPoints = ref.HitPoints;
		AttackDamage = ref.AttackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap Destructor called." << std::endl; }


void	ClapTrap::attack(const std::string& target) {
	if (EnergyPoints > 0 && HitPoints > 0) {
		std::cout << "ClapTrap " << Name << " attacks " << target
							<< " , causing " << AttackDamage
							<< " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else
		std::cout << "ClapTrap " << Name\
		<< " has no Points to attack!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (EnergyPoints > 0 && HitPoints > 0) {
		std::cout << "ClapTrap " << Name << " repairs " << "itself, getting "
							<< amount << " hit points back" << std::endl;
		HitPoints += amount;
		EnergyPoints--;
	}
	else
		std::cout << "ClapTrap " << Name
							<< " has no Points to repair itself!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << Name << " takes a hit "
						<< "causing " << amount << " Points of damage!" << std::endl;
	if ((unsigned int)HitPoints >= amount )
		HitPoints -= amount;
	else
		HitPoints = 0;
}

void	ClapTrap::displayStats( void ) {
	std::cout << Name << " 's Stats:\n"
		<< "HitPoints: " << HitPoints << std::endl
		<< "EnergyPoints: " << EnergyPoints << std::endl
		<< "AttackDamage: " << AttackDamage << std::endl;
}