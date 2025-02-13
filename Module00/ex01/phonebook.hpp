#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook {
    public:
        void addContact();
        void searchContact();
    private:
        Contact contacts[8];
        int contactCount;
};

#endif