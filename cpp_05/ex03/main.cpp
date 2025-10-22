#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    srand(time(NULL));
    Intern  someRandomIntern;
    AForm* form = NULL;

    std::cout << "--------------------------------------------\n";
    std::cout << "--- Test 1: Shrubbery (Sign OK, Exec FAIL) ---\n";
    std::cout << "--------------------------------------------\n";
    try {
        Bureaucrat bob("Bob", 140);
        std::cout << bob << std::endl;

        form = someRandomIntern.makeForm("shrubbery creation", "home");
        if (form) {
            std::cout << *form << std::endl;
            bob.signForm(*form);
            std::cout << *form << std::endl;
            bob.executeForm(*form); 

            delete form;
            form = NULL;
        }
    } catch (const std::exception& e) {
        std::cerr << "Caught an unexpected exception: " << e.what() << std::endl;
        if (form) {
            delete form;
            form = NULL;
        }
    }
    std::cout << "\n";

    std::cout << "-------------------------------------------\n";
    std::cout << "--- Test 2: Robotomy (Sign & Exec OK) ---\n";
    std::cout << "-------------------------------------------\n";
    try {
        Bureaucrat hermes("Hermes", 40);
        std::cout << hermes << std::endl;
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form) {
            std::cout << *form << std::endl;
            hermes.signForm(*form);
            hermes.executeForm(*form);
            delete form;
            form = NULL;
        }
    } catch (const std::exception& e) {
        std::cerr << "Caught an unexpected exception: " << e.what() << std::endl;
        if (form) {
            delete form;
            form = NULL;
        }
    }
    std::cout << "\n";

    std::cout << "--------------------------------------------------\n";
    std::cout << "--- Test 3: Presidential Pardon (Sign FAIL) ---\n";
    std::cout << "--------------------------------------------------\n";
    try {
        Bureaucrat lowlevel("Low-Level Guy", 30);
        std::cout << lowlevel << std::endl;

        form = someRandomIntern.makeForm("presidential pardon", "Marvin");
        if (form) {
            std::cout << *form << std::endl;
            lowlevel.signForm(*form);
            lowlevel.executeForm(*form);
            delete form;
            form = NULL;
        }
    } catch (const std::exception& e) {
        std::cerr << "Caught an unexpected exception: " << e.what() << std::endl;
        if (form) {
            delete form;
            form = NULL;
        }
    }
    std::cout << "\n";

    std::cout << "-------------------------------------------\n";
    std::cout << "--- Test 4: Non-existent form ---\n";
    std::cout << "-------------------------------------------\n";
    form = someRandomIntern.makeForm("request for coffee", "Intern");
    if (form == NULL) {
        std::cout << "Correctly handled non-existent form.\n";
    }
    return 0;
}
