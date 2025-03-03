#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"


class FragTrap : virtual public ClapTrap {

	public :
		FragTrap(std::string name);
		FragTrap(const FragTrap& ref);
		FragTrap&	operator=(const FragTrap& ref);
		~FragTrap();
		void	highFivesGuys(void);
};

#endif