#include "Identify.hpp"

int main() {

  srand(time(0));
  for (int i = 0; i < 10; ++i) {
      Base* randomInstance = generate();

      // using pointer
      std::cout << "Using pointer: ";
      identify(randomInstance);

      // using reference
      std::cout << "Using reference: ";
      identify(*randomInstance);

      delete randomInstance;
      std::cout << "---------------------" << std::endl;
  }

  return 0;
}