#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& ref) {
	if (this != &ref)
		ClapTrap::operator=(ref);
	return (*this);
}

FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

void	FragTrap::highFivesGuys(void) {
	std::cout << Name << " the FragTrap requests a positive high five!"
						<< std::endl;
}