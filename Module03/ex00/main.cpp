#include "ClapTrap.hpp"

int main()
{
  ClapTrap a("knight", 10, 10, 10);
  ClapTrap b("bichop", 5);
  ClapTrap c( b );
  ClapTrap d = a;

  a.attack("bichop");
  b.takeDamage(10);
  b.attack("knight");
  b.beRepaired(10);
  d.attack("knight");
}