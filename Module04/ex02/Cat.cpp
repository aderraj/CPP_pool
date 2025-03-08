#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
	std::cout << CYAN "Cat's " RESET
						<< GREEN "default constructor called." RESET
						<< std::endl;
}

Cat::Cat(const Cat& ref) : Animal(ref), brain(new Brain(*ref.brain)) {
	std::cout << CYAN "Cat's " RESET
						<< "copy constructor called." << std::endl;
}

Cat&	Cat::operator=(const Cat& ref) {
	if (this != &ref) {
		Animal::operator=(ref);
		delete brain;
		brain = new Brain(*ref.brain);
	}
	return (*this);
}

Cat::~Cat() {
	delete brain;
	std::cout << CYAN "Cat's " RESET
						<< RED "destructor called." RESET
						<< std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

void	Cat::exposeIdeas() {
	for (int i = 0; i < 100; i++)
		std::cout << brain->ideas[i] << std::endl;
}