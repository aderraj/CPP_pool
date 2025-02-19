#include <iostream>
#include "Zombie.hpp"

int main()
{
  Zombie obj("Foo");
  obj.annonce();
  Zombie *ptr;
  ptr = new Zombie("allocated");
  ptr->annonce();
  delete(ptr);
}
