#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

# define BLACK "\x1b[30m"
# define RED "\x1b[91m"
# define GREEN "\x1b[32m"
# define BRIGHT_GREEN "\x1b[92m"
# define BLUE "\x1b[34m"
# define YELLOW "\x1b[93m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define BG_BLACK "\x1b[40m"
# define BG_RED "\x1b[41m"
# define BG_GREEN "\x1b[42m"
# define BG_YELLOW "\x1b[43m"
# define BG_BLUE "\x1b[44m"
# define BG_MAGENTA "\x1b[45m"
# define BG_CYAN "\x1b[46m"
# define BG_WHITE "\x1b[47m"
# define BRIGHT_BLACK "\x1b[90m"  // Actually gray
# define BRIGHT_RED "\x1b[91m"
# define BRIGHT_GREEN "\x1b[92m"
# define BRIGHT_YELLOW "\x1b[93m"
# define BRIGHT_BLUE "\x1b[94m"
# define BRIGHT_MAGENTA "\x1b[95m"
# define BRIGHT_CYAN "\x1b[96m"
# define BRIGHT_WHITE "\x1b[97m"
# define RESET "\x1b[0m"
# define BOLD "\x1b[1m"
# define ITALIC "\x1b[3m"
# define UNDERLINE "\x1b[4m"

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

	private:
		std::string Name;
		unsigned int					HitPoints;
		unsigned int					EnergyPoints;
		unsigned int					AttackDamage;

};


#endif