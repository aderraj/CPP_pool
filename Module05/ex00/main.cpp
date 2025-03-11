#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat test("josh", -1);
  } catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
    std::cout << "catched" << std::endl;
  }
  
}