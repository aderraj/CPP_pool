#include "Animal.hpp"

Animal::Animal() : type("animal") {
	std::cout << YELLOW "Animal's " RESET
						<< GREEN "default constructor called" RESET
						<< std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << YELLOW "Animal's " RESET
						<< GREEN "constructor called" RESET
						<< std::endl;
}

Animal::Animal(const Animal& ref) : type(ref.type) {
	std::cout << YELLOW "Animal's " RESET
						<< GREEN "copy constructor called" RESET
						<< std::endl;
}

Animal&	Animal::operator=(const Animal& ref) {
	if (this != &ref)
		type = ref.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << YELLOW "Animal's " RESET
						<< RED "destructor called" RESET
						<< std::endl;
}

std::string	Animal::getType() const { return type; }

void				Animal::makeSound() const {
	std::cout << YELLOW "Animal's " RESET
						<< "sound coming." << std::endl;
}