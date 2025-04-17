#include <iostream>
#include <string>



// void printType(int n) {
//   switch (n) {
//     case CHAR:
//       std::cout << "CHAR\n";
//       break;
//     case INT:
//       std::cout << "INT\n";
//       break;
//     case FLOAT:
//       std::cout << "FLOAT\n";
//       break;
//     case DOUBLE:
//       std::cout << "DOUBLE\n";
//       break;
//     case PSDO_FLOAT:
//       std::cout << "PSEUDO FLOAT\n";
//       break;
//     case PSDO_DOUBLE:
//       std::cout << "PSEUDO DOUBLE\n";
//       break;
//     default:
//       std::cout << "UNKNOWN\n";
//   }
// }

#include <cmath>

int main (int ac, char** av) {
  std::string str = av[1];
  char *end;
  try {
  double value = static_cast<double>(strtof(str.c_str(), &end));
  std::cout << *end << std::endl;
  // if (end != NULL)
  //   std::cout << "Invalid NUM\n";
  // else
    std::cout << "num: " << value << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what();
  }
}