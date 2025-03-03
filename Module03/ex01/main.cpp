#include "ScavTrap.hpp"

int main()
{
    // Test constructors and inheritance
    std::cout << "Creating ScavTrap object:" << std::endl;
    ScavTrap scav("Guardian");
    scav.displayStats();
    std::cout << std::endl;

    // Test copy constructor
    std::cout << "Creating ClapTrap object:" << std::endl; 
    ClapTrap clap("Knight");
    clap.displayStats();
    std::cout << std::endl;

    // Test regular member functions
    std::cout << "Testing member functions:" << std::endl;
    scav.attack("Knight");
    clap.takeDamage(30);
    clap.beRepaired(20);
    clap.displayStats();
    std::cout << std::endl;

    // Test special capacity
    std::cout << "Testing special capacity:" << std::endl;
    scav.guardGate();
    std::cout << std::endl;

    // Test destruction order
    std::cout << "Testing destruction:" << std::endl;
    // Objects will be destroyed automatically when going out of scope
    // ScavTrap destructor should be called first, then ClapTrap destructor
    return 0;
}