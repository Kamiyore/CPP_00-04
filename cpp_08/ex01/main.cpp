#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main() {

    std::cout << "--- Test from subject ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 11-9=2
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl; // 17-3=14

    std::cout << "\n--- Test with 15,000 numbers ---" << std::endl;
    try {
        const unsigned int N = 15000;
        Span sp_large(N);
        std::vector<int> numbers_source;
        numbers_source.reserve(N);

        srand(time(NULL));
        for (unsigned int i = 0; i < N; ++i) {
            numbers_source.push_back(rand());
        }

        sp_large.addNumber(numbers_source.begin(), numbers_source.end());
        std::cout << "Shortest span: " << sp_large.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp_large.longestSpan() << std::endl;
        sp_large.addNumber(42); 
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    std::cout << "\n--- Exception Test ---" << std::endl;
    Span sp_exc(2);
    sp_exc.addNumber(1);
    sp_exc.addNumber(2);
    try {
        std::cout << "Trying to add a number to a full Span..." << std::endl;
        sp_exc.addNumber(3);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << '\n' << "Trying to find a span in a Span with 1 number..." << std::endl;
        Span sp_one(1);
        sp_one.addNumber(42);
        sp_one.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Expected exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}
