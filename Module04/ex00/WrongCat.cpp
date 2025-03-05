#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong Cat") {
	std::cout << MAGENTA "WrongCat's " RESET
						<< GREEN "default constructor called." RESET
						<< std::endl;
}

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref) {
	std::cout << MAGENTA "WrongCat's " RESET
						<< GREEN "copy constructor called." RESET
						<< std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& ref) {
	if (this != &ref)
		WrongAnimal::operator=(ref);
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << MAGENTA "WrongCat's " RESET
						<< RED "destructor called." RESET
						<< std::endl;
}
void	WrongCat::makeSound() const {
	std::cout << MAGENTA "WrongCat's " RESET
						<< "voice" << std::endl;
}