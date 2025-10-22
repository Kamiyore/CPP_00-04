#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Test1: Create valid objects and successfully sign a form
    try {
        Bureaucrat boris("Boris", 50);
        Form myForm("Tax Form", 60, 100);

        std::cout << boris << std::endl;
        std::cout << myForm << std::endl;

        boris.signForm(myForm);
        std::cout << myForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    //Test2: Create a Bureaucrat with a grade that is too low to sign the form
    try {
        Bureaucrat pavel("Pavel", 80);
        Form taxForm("Tax Form 2", 70, 120);

        std::cout << pavel << std::endl;
        std::cout << taxForm << std::endl;

        pavel.signForm(taxForm);
        std::cout << taxForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    //Test3: Create a form with an invalid grade (too high)
    try {
        Form invalidForm("Secret Form", 0, 10);
        std::cout << invalidForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test4 : Create a form with an invalid grade (too low)
    try {
        Form anotherInvalidForm("Final Form", 160, 150);
        std::cout << anotherInvalidForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
