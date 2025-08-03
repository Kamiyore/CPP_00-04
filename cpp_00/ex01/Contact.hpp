#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

class Contact
{
    private:
    std:: string firstName;
    std:: string lastName;
    std:: string nickname;
    std:: string phoneNumber;
    std:: string darkestSecret;
    public:

    /*setters makes private value writable*/
    void set_first_name(std::string& name);
    void set_last_name(std::string& name);
    void set_nickname(std::string& name);
    void set_phone_number(std::string& number);
    void set_darkest_secret(std::string& secret);

    /*getters makes the values readable*/
    std::string get_first_name();
    std::string get_last_name();
    std::string get_nickname();
    std::string get_phone_number();
    std::string get_darkest_secret();
};

#endif