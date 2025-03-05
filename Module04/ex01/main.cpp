#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

int main() {
    {
        // Testing deep copy
        Dog* dog1 = new Dog();
        dog1->makeSound();
        dog1->exposeIdeas();

        Dog* dog2 = new Dog(*dog1);
        dog2->makeSound();

        delete dog1;
        delete dog2;
    }

    {
        const int size = 6;
        Animal* animals[size];

        // Fill half with Dogs, half with Cats
        for (int i = 0; i < size / 2; i++)
            animals[i] = new Dog();
        for (int i = size / 2; i < size; i++)
            animals[i] = new Cat();

        // Optional checks or usage
        for (int i = 0; i < size; i++)
            animals[i]->makeSound();

        // Destruction
        for (int i = 0; i < size; i++)
            delete animals[i];
    }

    // Check memory leaks with tools like valgrind or similar
    return 0;
}