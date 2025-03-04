#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Name("default_name"), HitPoints(10),
											EnergyPoints(10), AttackDamage(0) {
	std::cout << YELLOW "ClapTrap's " RESET
						<< "default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name),
					HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << YELLOW "ClapTrap's " RESET
						<< GREEN "constructor called." RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref) : Name(ref.Name),
					HitPoints(ref.HitPoints), EnergyPoints(ref.EnergyPoints),
					AttackDamage(ref.AttackDamage) {
	std::cout << YELLOW "ClapTrap's " RESET
						<< BRIGHT_GREEN "copy constructor called." RESET
						<< std::endl;

}

ClapTrap&	ClapTrap::operator=(const ClapTrap& ref) {
	std::cout << YELLOW "ClapTrap's " RESET
						<< ITALIC BRIGHT_GREEN "copy operator= called." RESET 
						<< std::endl;
	if (this != &ref) {
		Name = ref.Name;
		HitPoints = ref.HitPoints;
		EnergyPoints = ref.HitPoints;
		AttackDamage = ref.AttackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << YELLOW "ClapTrap's " RESET
						<< RED "destructor called." RESET << std::endl;
}


void	ClapTrap::attack(const std::string& target) {
	if (EnergyPoints > 0 && HitPoints > 0) {
		std::cout << YELLOW "[ClapTrap] " CYAN << Name
							<< RESET " attacks " << target
							<< " , causing " << AttackDamage
							<< " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else
		std::cout << YELLOW "[ClapTrap] " CYAN << Name
							<< RESET " has no Points to attack!"
							<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (EnergyPoints > 0 && HitPoints > 0) {
		std::cout << YELLOW "[ClapTrap] " CYAN << Name
							<< RESET " repairs " << "itself, getting "
							<< amount << " hit points back" << std::endl;
		HitPoints += amount;
		EnergyPoints--;
	}
	else
		std::cout << YELLOW "[ClapTrap] " CYAN << Name
							<< RESET " has no Points to repair itself!"
							<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << YELLOW "[ClapTrap] " CYAN << Name
						<< RESET " takes a hit " << "causing "
						<< amount << " Points of damage!" << std::endl;
	if (HitPoints >= amount)
		HitPoints -= amount;
	else
		HitPoints = 0;
}

void	ClapTrap::displayStats( void ) {
	std::cout << BG_YELLOW BOLD BLACK << Name << "'s Stats:"
	<< RESET BOLD BRIGHT_CYAN << "\nHitPoints: " RESET << HitPoints
	<< BOLD BRIGHT_CYAN "\nEnergyPoints: " RESET << EnergyPoints
	<< BOLD BRIGHT_CYAN "\nAttackDamage: " RESET << AttackDamage
	<< std::endl;
}