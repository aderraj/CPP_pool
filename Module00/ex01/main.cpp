#include "phonebook.hpp"
#include <iostream>

int main() {
  Phonebook phonebook;
  std::string command;

  while (1) {
    std::cout << "-> Enter a command: ";
    std::getline(std::cin, command, '\n');
    if (std::cin.eof())
      break;
    else
    if (command == "EXIT")
      break;
    else if (command == "ADD")
      phonebook.addContact();
    else if (command == "SEARCH")
      phonebook.searchContact();
    else
      std::cout << RED "Invalid command." RESET << std::endl;
  }
  return 0;
}
