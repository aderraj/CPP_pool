#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Animal") {
	std::cout << BOLD BRIGHT_RED "WrongAnimal's " RESET
						<< GREEN "default constructor called" RESET
						<< std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << BOLD BRIGHT_RED "WrongAnimal's " RESET
						<< GREEN "constructor called" RESET
						<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref) : type(ref.type) {
	std::cout << BOLD BRIGHT_RED "WrongAnimal's " RESET
						<< GREEN "copy constructor called" RESET
						<< std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& ref) {
	if (this != &ref)
		type = ref.type;
	return (*this); 
}

WrongAnimal::~WrongAnimal() {
	std::cout << BOLD BRIGHT_RED "WrongAnimal's " RESET
						<< RED "destructor called" RESET
						<< std::endl;
}

std::string		WrongAnimal::getType() const { return (type); }

void	WrongAnimal::makeSound() const {
	std::cout << "Wrong Sound !" << std::endl;
}