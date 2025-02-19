#include "Harl.hpp"
#include <iostream>
# define RED "\x1b[31m"
# define RESET "\x1b[0m"


void	Harl::debug( void ) {
	std::cout << "I love having extra bacon for my"
	"7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< std::endl;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money."
	"You didn’t put enough bacon in my burger! If you did, I wouldn’t"
	"be asking for more!" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free."
	"I've been coming for years whereas you started working here since"
	"last month." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager"
	"now." << std::endl;
}

void	Harl::complain( std::string level ) {

	int					i;
	t_harl_map	map[4] = {
								{"debug", &Harl::debug},
								{"info", &Harl::info},	
								{"warning", &Harl::warning},
								{"error", &Harl::error}
								};

	for (size_t i = 0 ; i < level.length(); i++)
		level[i] = tolower(level[i]);

	for (i = 0; i < 4; i++)
		if (level == map[i].level)
			(this->*map[i].func)();
	if (i == 4)
		std::cerr << RED "Invalid level" RESET << std::endl;
}