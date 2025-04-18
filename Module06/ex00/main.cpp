#include "ScalarConverter.hpp"

int main (int ac, char** av) {

  if (ac != 2) {
    std::cerr << RED "Invalid args" RESET << std::endl;
    return 0;
  }

  std::string literal = av[1];
  if (!isValidLiteral(literal)) {
    std::cerr << RED "invalid literal" RESET << std::endl;
    return 0;
  }
  ScalarConverter::convert(literal);
}