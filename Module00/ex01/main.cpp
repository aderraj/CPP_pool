#include "phonebook.hpp"
#include <iostream>

bool	is_number(std::string& str) {

	for (char c : str)
		if (!std::isdigit(c))
			return false;

	return true;
}

void	flush_input(std::string& input) {

		std::cin.clear();
		clearerr(stdin);
		std::cin.rdbuf()->pubseekpos(0);
		input.clear();

		std::cout << std::endl;
}

bool	str_isprint(std::string& str) {

	for (char c : str)
		if (!isprint(c))
				return (false);

	return (true);
}

int main() {
  Phonebook phonebook;
  std::string command;
  
  while (1) {
    std::cout << CYAN "--> " RESET << "Enter a command: ";
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
