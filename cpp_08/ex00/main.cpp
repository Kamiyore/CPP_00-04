#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() {

    std::vector<int>my_vector;
    my_vector.push_back(10);
    my_vector.push_back(20);
    my_vector.push_back(42);
    try {
        std::cout<<"Inside vector: "<< my_vector[0] << ", "<< my_vector[1]<< ", " << my_vector[2] << "\n";
        std::cout << "Searching in vector..." << std::endl;
        easyfind(my_vector, 20);
        easyfind(my_vector, 10);
        easyfind(my_vector, 43);
    }
    catch (const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

// list is linked list, vector is array, and deque is double ended queue
    std::cout << "\n--- Testing with std::list<int> ---" << std::endl;
    std::list<int> my_list;
    my_list.push_back(100);
    my_list.push_back(-50);
    my_list.push_back(42);
    my_list.push_back(-8797765);
    my_list.push_back(0);

    try {
        std::cout << "Searching for 100..." << std::endl;
        easyfind(my_list, 100);

        std::cout << "Searching for -50..." << std::endl;
        easyfind(my_list, -50);

        std::cout << "Searching for 999..." << std::endl;
        easyfind(my_list, 999);
    }
    catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing with std::deque<int> ---" << std::endl;
    std::deque<int> my_deque;
    my_deque.push_back(77);
    my_deque.push_front(-77);
    my_deque.push_back(154);
    my_deque.push_front(0);

    try {
        std::cout << "Searching for -77..." << std::endl;
        easyfind(my_deque, -77);

        std::cout << "Searching for 0..." << std::endl;
        easyfind(my_deque, 0);

        std::cout << "Searching for 1..." << std::endl;
        easyfind(my_deque, 1);
    }
    catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    return 0;
}
