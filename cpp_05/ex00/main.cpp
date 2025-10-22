#include "Bureaucrat.hpp"

int main()
{
       //Test 1: Initializing a bureaucrat with a valid grade
    try {
        Bureaucrat validBureaucrat("Tanaka", 75);
        std::cout << validBureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    //Test2 : Initializing a bureaucrat with a grade too high (0)
    try {
        Bureaucrat tooHighBureaucrat("Tanaka", 0);
        std::cout << tooHighBureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    //Test 3: Initializing a bureaucrat with a grade too low (151)
    try {
        Bureaucrat tooLowBureaucrat("Kazu", 151);
        std::cout << tooLowBureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    //Test 4: increasing the grade of a bureaucrat who already has grade 1
    try {
        Bureaucrat highGradeBureaucrat("Kazuno", 2);
        std::cout << highGradeBureaucrat << std::endl;
        highGradeBureaucrat.incrementGrade();
        std::cout << highGradeBureaucrat << std::endl;
        highGradeBureaucrat.incrementGrade();
        std::cout << highGradeBureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    // Test 5: Decreasing the grade of a bureaucrat who already has grade 150
    try {
        Bureaucrat lowGradeBureaucrat("Eva", 149);
        std::cout << lowGradeBureaucrat << std::endl;
        lowGradeBureaucrat.decrementGrade();
        std::cout << lowGradeBureaucrat << std::endl;
        lowGradeBureaucrat.decrementGrade();
        std::cout << lowGradeBureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
