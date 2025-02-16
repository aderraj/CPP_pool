#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook() { contact_count = 0; };

std::string	prompt_user(std::string prompt) {

	std::string input;

	do {
			std::cout << prompt;
			std::getline(std::cin, input, '\n');
        if (std::cin.eof()) {
            std::cin.clear();
            clearerr(stdin);
            std::cin.rdbuf()->pubseekpos(0);
            input.clear();
            std::cout << std::endl;
            continue;
        }
	} while (input.empty() == true);

	return input;
}

void	requestContactInfo(std::string (&args)[5]) {

	args[0] = prompt_user(CYAN "Enter first name: " RESET);
	args[1] = prompt_user(CYAN "Enter last name: " RESET);
	args[2] = prompt_user(CYAN "Enter nickname: " RESET);
	args[3] = prompt_user(CYAN "Enter phone number: " RESET);
	args[4] = prompt_user(CYAN "Enter darkest secret: " RESET);

}

void	Phonebook::addContact() {

	std::string args[5];
	static int	old;

		if (contact_count < 8) {
				requestContactInfo(args);
				contacts[contact_count] = Contact(args[0], args[1], args[2], args[3], args[4]);
				contact_count++;
		} else {
				std::cout << YELLOW "Phonebook is full." RESET << std::endl;
				if (prompt_user(GREEN "Replace the oldest contact? (y/n): " RESET) == "y") {
						requestContactInfo(args);
						contacts[old] = Contact(args[0], args[1], args[2], args[3], args[4]);
						old++;
				}
				else
						std::cout << RED "Contact not added." RESET << std::endl;
		}
		if (old >= 8)
			old = 0;
}

void	display_field(std::string str) {
	if (str.length() > 9)
		std::cout << std::setw(10) << std::right << str.substr(0, 9) +  ".";
	else
		std::cout << std::setw(10) << std::right << str;
	std::cout << BLUE "|" RESET;
}

void	displayContactList(Contact (&contacts)[8], int contacts_count) {

	std::cout << YELLOW "---------------------------------------------" RESET << std::endl;
	std::cout << YELLOW "|" << GREEN << std::setw(10) << "  INDEX  " << RESET;
	std::cout << YELLOW "|" RESET << std::setw(10) << "   Name   ";
	std::cout << YELLOW "|" RESET << std::setw(10) << " LastName ";
	std::cout << YELLOW "|" RESET << std::setw(10) << " NickName " << YELLOW "|\n" RESET;
	// std::cout << "| Index | First Name | Last Name | Nickname |" << std::endl;
	std::cout << YELLOW "---------------------------------------------" RESET << std::endl;

	for (int i = 0; i < contacts_count; i++) {
		std::cout << BLUE "|" RESET;
		std::cout << std::setw(10) << std::right << i << BLUE "|" RESET;
		display_field(contacts[i].get_first_name());
		display_field(contacts[i].get_last_name());
		display_field(contacts[i].get_nickname());
		std::cout << std::endl;
	}
	if (contacts_count)
		std::cout << YELLOW "---------------------------------------------" RESET << std::endl;
}

void	Phonebook::searchContact(){
	
	int index;
	std::string input;

	displayContactList(contacts, contact_count);
	if (contact_count == 0) {
		std::cout << YELLOW BOLD "No contacts to display." RESET << std::endl;
		std::cout << YELLOW "---------------------------------------------" RESET << std::endl;
		return;
	}
	do {
		std::cout << GREEN "Enter index of contact: " RESET;
		std::getline(std::cin, input, '\n');
		if (!std::cin.eof())
			index = std::stoi(input);
	} while (!input.empty() && (index < 0 || index >= contact_count));

	std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
	std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
}

