#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {

	private :
		std::string name;
	
	public:
		Zombie(std::string name = "");
		void	setName(std::string new_name);
		void	annonce( void );
};

Zombie*	zombieHorde( int N, std::string name );
#endif