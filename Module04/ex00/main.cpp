#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
int main()
{
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  meta->makeSound();

  const WrongAnimal* meta_2 = new WrongAnimal();
  const WrongAnimal* i_2 = new WrongCat();
  std::cout << i_2->getType() << " " << std::endl;
  i_2->makeSound(); //will output the cat sound!
  meta_2->makeSound();
  delete i_2;
  delete i;
  delete j;
  delete meta;
  delete meta_2;
return 0;
}