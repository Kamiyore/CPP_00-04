#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

std::string format_field(const std::string& str);


class PhoneBook
{
    private:
    Contact contacts[8];
    int index;
    int count;

    public:
    PhoneBook(): index(0), count(0) {};
    /*ADD*/
    void add_contact(const Contact& c);
    /*SEARCH*/
    void all_contacts();
    int designated_contact(std:: string contactIndex);
};

#endif