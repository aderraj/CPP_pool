#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {

	public:
		ClapTrap(std::string name, int hitPoints = 10,
							int energyPoints = 10, int attackDamage = 0);
		ClapTrap(const ClapTrap& ref);
		ClapTrap&	operator=(const ClapTrap& ref);
		~ClapTrap();
		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

	private :
		std::string Name;
		int					HitPoints;
		int					EnergyPoints;
		int					AttackDamage;

};

#endif