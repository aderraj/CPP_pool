#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()){
	std::cout << MAGENTA "Dog's " RESET
						<< GREEN "default constructor called." RESET
						<< std::endl;
}

Dog::Dog(const Dog& ref) : Animal(ref), brain(new Brain()) {
	for (int i = 0; i < 100 ; i++)
		brain->ideas[i] = ref.brain->ideas[i];
	std::cout << MAGENTA "Dog's " RESET
						<< "copy constructor called." << std::endl;
}

Dog&	Dog::operator=(const Dog& ref) {
	if (this != &ref)
		Animal::operator=(ref);
	return (*this);
}

Dog::~Dog() {
	delete brain;
	std::cout << MAGENTA "Dog's " RESET
						<< RED "destructor called." RESET
						<< std::endl;
}

void	Dog::makeSound() const{
	std::cout << "Woof Woof!" << std::endl;
}

void	Dog::exposeIdeas() {
		for (int i = 0; i < 100; i++)
			std::cout << brain->ideas[i] << std::endl;
}
