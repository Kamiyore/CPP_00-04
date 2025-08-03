# include "PhoneBook.hpp"
# include "Contact.hpp"

    void Contact::set_first_name(std::string& name)
    {
         this->firstName = name;
    }
    void Contact::set_last_name(std::string& name)
    {
        this->lastName = name;
    }
    void Contact::set_nickname(std::string& name)
    {
        this->nickname = name;
    }
    void Contact::set_phone_number(std::string& number)
    {
        this->phoneNumber = number;
    }
    void Contact::set_darkest_secret(std::string& secret)
    {
        this->darkestSecret = secret;
    }
    
    std::string Contact::get_first_name()
    {
        return firstName;
    }
    std::string Contact::get_last_name()
    {
        return lastName;
    }
    std::string Contact::get_nickname()
    {
        return nickname;
    }
    std::string Contact::get_phone_number()
    {
        return phoneNumber;
    }
    std::string Contact::get_darkest_secret()
    {
        return darkestSecret;
    }
