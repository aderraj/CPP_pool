#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Testing ScavTrap ===" << std::endl;
    // ScavTrap tests remain the same
    ScavTrap scav("Guardian");
    std::cout << std::endl;

    std::cout << "=== Testing FragTrap ===" << std::endl;
    FragTrap frag("Warrior");
    std::cout << std::endl;

    // Test FragTrap member functions
    std::cout << "Testing FragTrap member functions:" << std::endl;
    scav.attack("Warrior");
    frag.takeDamage(50);
    frag.beRepaired(30);
    frag.displayStats();
    std::cout << std::endl;

    // Test FragTrap special capacity
    std::cout << "Testing FragTrap special capacity:" << std::endl;
    frag.highFivesGuys();
    std::cout << std::endl;

    // Compare both types
    std::cout << "=== Comparing both types ===" << std::endl;
    scav.displayStats();
    std::cout << std::endl;
    frag.displayStats();
    std::cout << std::endl;

    std::cout << "=== Testing destruction order ===" << std::endl;
    return 0;
}