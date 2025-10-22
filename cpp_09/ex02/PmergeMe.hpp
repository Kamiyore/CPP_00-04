#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>
#include <sys/time.h>
#include <set>
#include <climits>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& rhs);
    void run(int argc, char** argv);

private:
    std::vector<int> _vec_orig;
    std::vector<int> _vec;
    std::deque<int>  _deq;
    double _vec_time;
    double _deq_time;

    void parseArguments(int argc, char** argv);
    void sortVector();
    void sortDeque();
    void fordJohnsonSort(std::vector<int>& container);
    void fordJohnsonSort(std::deque<int>& container);
};

template <typename Container>
void printContainer(const Container& container, bool limit) {
    typename Container::const_iterator it = container.begin();
    size_t count = 0;
    size_t display_limit = limit ? 10 : (size_t)-1;

    while (it != container.end() && count < display_limit) {
        if (it != container.begin()) {
            std::cout << " ";
        }
        std::cout << *it;
        ++it;
        ++count;
    }
    if (limit && container.size() > display_limit)
        std::cout << " [...]";
}
#endif
