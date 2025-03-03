#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& ref);
		ClapTrap&	operator=(const ClapTrap& ref);	
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	displayStats( void );

	protected:
		std::string Name;
		int					HitPoints;
		int					EnergyPoints;
		int					AttackDamage;

};


#endif