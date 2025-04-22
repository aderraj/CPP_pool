#include "Array.hpp"
#include <string>

int main () {
  Array<int> obj;
  Array<char> str(10);

  std::cout << "int array size: " << obj.size() << std::endl;
  std::cout << "char array size: " << str.size() << std::endl;
  for (size_t i = 0; i < str.size(); i++)
    str[i] = '1';

  Array<char> test(str);
  std::cout << "copied array size: " << test.size() << std::endl;

  // proof of deep copy
    test[0] = '2';
    std::cout << "src array[0]: " << str[0] << std::endl;

  try {
    str[10] = 'x';
  } catch (std::exception &e) {
    std::cout << "invalid idx" << std::endl;
  }

  std::cout << "original array content: " << std::endl;
  for (size_t i = 0; i < str.size(); i++)
    std::cout << str[i];
  std::cout << std::endl << std::endl;


  Array<std::string> strings(5);

  std::cout << "default strings values: " << std::endl;
  for (size_t i = 0; i < strings.size(); i++)
    std::cout << strings[i];
  std::cout << std::endl;

  strings[0] = "1337";
  strings[1] = "future";
  strings[2] = "is";
  strings[3] = "loading";
  strings[4] = "/>";

  std::cout << "assigned strings values: " << std::endl;
  for (size_t i = 0; i < strings.size(); i++)
    std::cout << strings[i] << " ";
  std::cout << std::endl;
}