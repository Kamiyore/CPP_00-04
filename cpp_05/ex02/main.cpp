#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));

    //test 1 : Create a valid ShrubberyCreationForm and execute it with a signed Bureaucrat
    try {
        Bureaucrat boris("Boris", 130);
        ShrubberyCreationForm form1("home");

        std::cout << boris << std::endl;
        std::cout << form1 << std::endl;

        boris.signForm(form1);
        boris.executeForm(form1);

        std::cout << form1 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // test2: Create a valid RobotomyRequestForm
    try {
        Bureaucrat pavel("Pavel", 40);
        RobotomyRequestForm form2("robot");

        std::cout << pavel << std::endl;
        std::cout << form2 << std::endl;

        pavel.signForm(form2);
        pavel.executeForm(form2);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    //test3 : Create a valid PresidentialPardonForm and execute it with a signed Bureaucrat
    try {
        Bureaucrat zaphod("Zaphod", 4);
        PresidentialPardonForm form3("Arthur Dent");

        std::cout << zaphod << std::endl;
        std::cout << form3 << std::endl;

        zaphod.signForm(form3);
        zaphod.executeForm(form3);
        std::cout << form3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

     // test4: Create a RobotomyRequestForm and try to execute it with a Bureaucrat (too low grade)
    try {
        Bureaucrat nelly("Nelly", 80);
        RobotomyRequestForm form4("robot");

        std::cout << nelly << std::endl;
        std::cout << form4 << std::endl;

        nelly.signForm(form4);
        nelly.executeForm(form4);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    //test 5: Attempt to execute an unsigned form
    try {
        Bureaucrat boss("Boss", 2);
        PresidentialPardonForm form5("Ford Prefect");

        std::cout << boss << std::endl;
        std::cout << form5 << std::endl;
        
        // Purposefully skip signing the form
        boss.executeForm(form5);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
