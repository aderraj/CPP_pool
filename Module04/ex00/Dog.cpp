#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << MAGENTA "Dog's " RESET
						<< GREEN "default constructor called." RESET
						<< std::endl;
}

Dog::Dog(const Dog& ref) : Animal(ref) {
	std::cout << MAGENTA "Dog's " RESET
						<< "copy constructor called." << std::endl;
}

Dog&	Dog::operator=(const Dog& ref) {
	if (this != &ref)
		Animal::operator=(ref);
	return (*this);
}

Dog::~Dog() {
	std::cout << MAGENTA "Dog's " RESET
						<< RED "destructor called." RESET
						<< std::endl;
}

void	Dog::makeSound() const{
	std::cout << "Woof Woof!" << std::endl;
}