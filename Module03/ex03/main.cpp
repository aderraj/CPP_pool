#include "DiamondTrap.hpp"

int main()
{
    std::cout << "=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap diamond("Ultimate");
    std::cout << std::endl;

    DiamondTrap diamond2("royal");
    diamond2.displayStats();
    std::cout << std::endl;

    // Test member functions inherited from ClapTrap
    std::cout << "=== Testing inherited ClapTrap functions ===" << std::endl;
    diamond.attack("Enemy");
    diamond2.takeDamage(20);
    diamond2.beRepaired(10);
    diamond2.displayStats();
    std::cout << std::endl;

    // Test ScavTrap special ability
    std::cout << "=== Testing ScavTrap ability ===" << std::endl;
    diamond.guardGate();
    std::cout << std::endl;

    // Test FragTrap special ability
    std::cout << "=== Testing FragTrap ability ===" << std::endl;
    diamond.highFivesGuys();
    std::cout << std::endl;

    // Test DiamondTrap special ability
    std::cout << "=== Testing DiamondTrap special ability ===" << std::endl;
    diamond.whoAmI();
    std::cout << std::endl;

    // Test that diamond inherits correct attributes
    std::cout << "=== Testing inherited attributes ===" << std::endl;
    diamond.displayStats();
    std::cout << std::endl;

    std::cout << "=== Testing destruction order ===" << std::endl;
    return 0;
}