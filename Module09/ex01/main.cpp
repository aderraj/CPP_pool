#include "RPN.hpp"

int main (int ac, char **av) {
  if (ac != 2)
    return (std::cerr << "Error: Invalid args!\n", 0);
  try { rpn(av[1]); }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}