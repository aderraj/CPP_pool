#include "Brain.hpp"
#include <sstream>

Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		std::stringstream ss;
		ss << "Idea #" << i;
		ideas[i] = ss.str();
	}
	std::cout << "Brain's constructor called." << std::endl;
}

Brain::Brain(const Brain& copy) {
	for (int i = 0; i < 100; ++i)
		ideas[i] = copy.ideas[i];
}

Brain&	Brain::operator=(const Brain& ref) {
	if (this != &ref) {
		for (int i = 0; i < 100; ++i)
			ideas[i] = ref.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain's destructor called." << std::endl;
}

