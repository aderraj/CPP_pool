#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << CYAN "Cat's " RESET
						<< GREEN "default constructor called." RESET
						<< std::endl;
}

Cat::Cat(const Cat& ref) : Animal(ref) {
	std::cout << CYAN "Cat's " RESET
						<< "copy constructor called." << std::endl;
}

Cat&	Cat::operator=(const Cat& ref) {
	if (this != &ref)
		Animal::operator=(ref);
	return (*this);
}

Cat::~Cat() {
	std::cout << CYAN "Cat's " RESET
						<< RED "destructor called." RESET
						<< std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}