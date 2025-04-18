#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	public:
		Dog();
		Dog(const Dog& ref);
		Dog&	operator=(const Dog& ref);
		~Dog();
		void	makeSound() const;
		void	exposeIdeas();

	private:
		Brain*	brain;
};

#endif