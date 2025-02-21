#include "Harl.hpp"
#include <iostream>
# define RED "\x1b[31m"
# define RESET "\x1b[0m"

int getLevelIdx( std:: string level) {

	if (level == "DEBUG") return (0);
	if (level == "INFO") return (1);
	if (level == "WARNING") return (2);
	if (level == "ERROR") return (3);
	return (-1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << RED "Error: Invalid args" RESET << std::endl, 1);

	Harl	harl;
	switch (getLevelIdx(av[1])) {
		case 0 :
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("debug");
			std::cout << std::endl;
		case 1 :
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("info");
			std::cout << std::endl;
		case 2 :
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("warning");
			std::cout << std::endl;
		case 3 :
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("error");
			std::cout << std::endl;
			break ;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}