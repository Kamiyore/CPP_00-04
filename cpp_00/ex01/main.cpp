# include "PhoneBook.hpp"
# include "Contact.hpp"

std::string format_field(const std::string& str)
{
    if(str.length() > 10)
        return str.substr(0,9) + ".";
    else
    return str;
}

bool validate_input(const std::string& prompt, std:: string& target)
{
    std:: cout << prompt;
    if(!std::getline(std::cin, target))
        return false;
    if(target.empty())
        return false;  
    return true;
}
bool save_info(Contact &c)
{

    std::string input;
     
    if (!validate_input("Enter first name: ", input)) return false;
    c.set_first_name(input);

    if (!validate_input("Enter last name: ", input)) return false;
    c.set_last_name(input);

    if (!validate_input("Enter nickname: ", input)) return false;
    c.set_nickname(input);

    if (!validate_input("Enter phone number: ", input)) return false;
    c.set_phone_number(input);

    if (!validate_input("Enter darkest secret: ", input)) return false;
    c.set_darkest_secret(input);
    return true;
}

int main(void)
{
    std::string command;
    PhoneBook phonebook;

    while (true)
    {
        std::cout << "Enter command: ";
        if (!std::getline(std::cin, command))
        {
            std::cout << std::endl;
            break;
        }
        if (command == "ADD")
        {
            Contact contact;
            if (!save_info(contact))
            {
                if (std::cin.eof())
                {
                    std::cout << std::endl;
                    break;
                }
                std::cout << "All fields must be filled. Contact was not saved." << std::endl;
            }
            else
                phonebook.add_contact(contact);
        }
        else if (command == "SEARCH")
        {
            phonebook.all_contacts();
            std::cout << "Which contact you want to search?: ";
            if (!std::getline(std::cin, command))
            {
                std::cout << std::endl;
                break;
            }
            phonebook.designated_contact(command);
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command. Only ADD, SEARCH or EXIT accepted." << std::endl;
    }
    return 0;
}
