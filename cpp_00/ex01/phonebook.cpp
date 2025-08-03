# include "PhoneBook.hpp"
# include "Contact.hpp"

    /*ADD*/
    void PhoneBook:: add_contact(const Contact& c)
    {
        contacts[index] = c;
        index = (index + 1) % 8;
        if(count < 8)
        count++;
    }
    /*SEARCH*/
    int PhoneBook:: designated_contact(std:: string contactIndex)
    {
        int con;
        std::stringstream ss(contactIndex);
        if (!(ss >> con) || !ss.eof())
     {
            std::cout << "Invalid index." << std::endl;
            return -1;
        }
        if (con < 0 || con >= count)
        {
            std::cout << "Index out of range." << std::endl;
            return -1;
        }
        
        else
        {
            std::cout << "Index: "<< con << std:: endl;
            std::cout << "First Name: " << contacts[con].get_first_name()<< std:: endl;
            std::cout << "Last Name: " << contacts[con].get_last_name()<< std:: endl;
            std::cout << "Nickname: " << contacts[con].get_nickname()<< std:: endl;
            std::cout << "Phone number: " << contacts[con].get_phone_number()<< std:: endl;
            std::cout << "Darkest Secret: " << contacts[con].get_darkest_secret()<< std:: endl;
        }
        return (0);
    }
    
     void PhoneBook:: all_contacts()
     {
        {
            std::cout << std::setw(10) << "Index" << "|"
                      << std::setw(10) << "First Name" << "|"
                      << std::setw(10) << "Last Name" << "|"
                      << std::setw(10) << "Nickname" << std::endl;
        
            for (int i = 0; i < count; i++)
            {
                std::cout << std::setw(10) << i << "|"
                          << std::setw(10) << format_field(contacts[i].get_first_name()) << "|"
                          << std::setw(10) << format_field(contacts[i].get_last_name()) << "|"
                          << std::setw(10) << format_field(contacts[i].get_nickname()) << std::endl;
            }
        }
     }