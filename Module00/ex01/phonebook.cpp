#include "phonebook.hpp"
#include <iostream>

std::string prompt_user(std::string prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input, '\n');
    return input;
}


void Phonebook::addContact() {
    std::string args[5];

    if (contactCount < 8) {
        args[0] = prompt_user("Enter first name: ");
        args[1] = prompt_user("Enter last name: ");
        args[2] = prompt_user("Enter nickname: ");
        args[3] = prompt_user("Enter phone number: ");
        args[4] = prompt_user("Enter darkest secret: ");
        contacts[contactCount] = Contact(args[0], args[1], args[2], args[3], args[4]);
        contactCount++;
    } else {
        std::cout << "Phonebook is full.\n" << std::endl;
        if (prompt_user("Replace the oldest contact? (y/n): ") == "y") {
            args[0] = prompt_user("Enter first name: ");
            args[1] = prompt_user("Enter last name: ");
            args[2] = prompt_user("Enter nickname: ");
            args[3] = prompt_user("Enter phone number: ");
            args[4] = prompt_user("Enter darkest secret: ");
            contacts[0] = Contact(args[0], args[1], args[2], args[3], args[4]);
        }
        else
            std::cout << "Contact not added.\n" << std::endl;
    }
}

void Phonebook::searchContact(){
	
}