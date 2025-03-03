#include "ClapTrap.hpp"

int main()
{
  ClapTrap a("knight");
  ClapTrap b("bichop");
  ClapTrap c( b );
  ClapTrap d = a;

  a.attack("bichop");
  b.takeDamage(10);
  b.attack("knight");
  b.beRepaired(10);
  d.attack("knight");
  a.displayStats();
  b.displayStats();
}