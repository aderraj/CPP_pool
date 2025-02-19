#include "Harl.hpp"
#include <iostream>


int main()
{
    Harl harl;
    
    std::cout << "Testing debug level:" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "\nTesting info level:" << std::endl;
    harl.complain("info");
    
    std::cout << "\nTesting warning level:" << std::endl;
    harl.complain("WaRNinG");
    
    std::cout << "\nTesting error level:" << std::endl;
    harl.complain("error");
    
    std::cout << "\nTesting invalid level:" << std::endl;
    harl.complain("invalid");
    
    return 0;
}