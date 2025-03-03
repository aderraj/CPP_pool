#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {

	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& ref);
		DiamondTrap&	operator=(const DiamondTrap& ref);
		~DiamondTrap();
		void whoAmI();
		using ScavTrap::attack;

	private :
		std::string	Name;

};

#endif