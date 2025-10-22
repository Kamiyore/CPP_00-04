#include "PmergeMe.hpp"
#include <cstdlib>

static double startTime() {
    struct timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec * 1e6 + tv.tv_usec;
}

void PmergeMe::run(int argc, char** argv) {
    this->parseArguments(argc, argv);
    this->_vec_orig = this->_vec;
    double startTimeVec = startTime();
    this->sortVector();
    double endTimeVec = startTime();
    this->_vec_time = endTimeVec - startTimeVec;
    double startTimeDeq = startTime();
    this->sortDeque();
    double endTimeDeq = startTime();
    this->_deq_time = endTimeDeq - startTimeDeq;
    std::cout << "Before: ";
    printContainer(this->_vec_orig, true);
    // std::cout << std::endl;
    // std::cout << "Vector After:  ";
    // printContainer(this->_vec, false);
    std::cout << "\nDeque After:  ";
    printContainer(this->_deq, false);
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Time to process a range of " << this->_vec.size()
              << " elements with std::vector : " << this->_vec_time << " us" << std::endl;         
    std::cout << "Time to process a range of " << this->_deq.size()
              << " elements with std::deque  : " << this->_deq_time << " us" << std::endl;
}

void PmergeMe::sortVector() {
    fordJohnsonSort(_vec);
}

void PmergeMe::sortDeque() {
    fordJohnsonSort(_deq);
}
int main(int argc, char** argv) {
    PmergeMe sorter;
    try {
        sorter.run(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
