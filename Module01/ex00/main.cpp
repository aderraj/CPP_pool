#include <iostream>
#include "Zombie.hpp"

int main()
{
  Zombie obj("Foo");
  obj.annonce();
  Zombie *ptr;
  ptr = newZombie("new one");
  ptr->annonce();
  randomChump("chump");
  delete(ptr);
}
