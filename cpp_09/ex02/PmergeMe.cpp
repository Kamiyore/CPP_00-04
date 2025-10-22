#include "PmergeMe.hpp"
#include <algorithm>
#include <vector>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        this->_vec = rhs._vec;
        this->_deq = rhs._deq;
    }
    return *this;
}

void PmergeMe::parseArguments(int argc, char **argv)
{
    if (argc < 2)
    {
        throw std::runtime_error("Error");
    }
    _vec.clear();
    _deq.clear();
    std::set<int> seenNumbers;
    for (int i = 1; i < argc; ++i)
    {
        char *endptr = NULL;
        long parsedLong = strtol(argv[i], &endptr, 10);
        if (argv[i][0] == '\0' || *endptr != '\0' || parsedLong <= 0 || parsedLong > INT_MAX)
        {
            throw std::runtime_error("Error");
        }
        int number = static_cast<int>(parsedLong);
        if (!seenNumbers.insert(number).second)
        {
            throw std::runtime_error("Error");
        }
        _vec.push_back(number);
        _deq.push_back(number);
    }
}

// =================== ALGORITHM FOR VECTOR ==========================
void PmergeMe::fordJohnsonSort(std::vector<int> &vec)
{
    const size_t n = vec.size();
    if (n < 2)
        return;

    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    for (size_t i = 0; i + 1 < n; i += 2)
    {
        if (vec[i] < vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1])); // (min, max)
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }
    if (n % 2 != 0)
        straggler = vec.back();
    std::vector<int> largerElements;
    largerElements.reserve(pairs.size());
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        largerElements.push_back(pairs[i].second);
    }
    fordJohnsonSort(largerElements);
    // by here we have sorted the biggest numbers in aceding order in each pair
    std::vector<std::pair<int, int> > sortedPairs;
    sortedPairs.reserve(pairs.size());
    for (size_t i = 0; i < largerElements.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (largerElements[i] == pairs[j].second)
            {
                sortedPairs.push_back(pairs[j]);
                break;
            }
        }
    }
    // be here we have the pairs sorted by its bigger number
    const size_t pairCount = sortedPairs.size();
    std::vector<int> mainChain;
    std::vector<int> pendChain;
    mainChain.reserve(n);
    for (size_t k = 0; k < pairCount; ++k)
    {
        mainChain.push_back(sortedPairs[k].second);
        pendChain.push_back(sortedPairs[k].first);
    }
    if (pairCount > 0)
    {
        mainChain.insert(mainChain.begin(), pendChain[0]); // we insert the first number from pend chain
    }
    // below we create bigNumPos value and initialize positions for the bigger numbers
    // and update the position of the numbers in the main chain because we inserted one number from pend chain
    std::vector<size_t> biggerNumberPosition(pairCount, 0);
    if (pairCount > 0)
    {
        for (size_t k = 0; k < pairCount; ++k)
        {
            biggerNumberPosition[k] = k + 1;
        }
    } // jacob[i]   [0][1][2][3][4][5]
      // this code below generates the jacob.vector 0  1  1  3  5 11 21, ...
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);                                              // insert 0 and 1
    while (jacob.back() < pendChain.size())                          // while the number of the jacobsthal is smaller than the length of pen chain, we are adding
        jacob.push_back(jacob.back() + 2 * jacob[jacob.size() - 2]); // (ex. if pend has 8 numbers, the last generated nmber wll be 11)

    size_t last_jacob = 1; // last jacob number we used for pend numbers default is[1]
    for (size_t i = 2; i < jacob.size(); ++i)
    {
        size_t current_jacob = jacob[i];
        // we are starting with the jacob. number 2 but it does not anything so the foor loop will stop at number 3
        // below we check if the jacob. num. is not bigger than the pend chain
        // if yes, we will use the pend chain size as a limit
        size_t limit = (current_jacob > pendChain.size()) ? pendChain.size() : current_jacob;
        // this for loop starts at the end of the end chain (from limit(3) to the jacob num(1)(here it will takes two numbers) )
        for (size_t pendIndex = limit; pendIndex > last_jacob; --pendIndex)
        {
            const size_t k = pendIndex;
            // Get the actual value of the smaller element to insert from the pendChain.
            // (Exm. pendIndex - 1 is 2. smallerElement gets pendChain[2])
            const int smallerElement = pendChain[pendIndex - 1];
            const size_t partnerIndex = k - 1;                                                        // this only chcecks who is its parter. Id pend chain is a3, partner will be b3 which is [2] (thats why -1)
            std::vector<int>::iterator upTo = mainChain.begin() + biggerNumberPosition[partnerIndex]; // this checks for real current position (ex. mainchain [4,6,8,9] bigNumPos [1,2,3,4] so bigNumPos[2] means that on second position is 2 and this 2 is and  ont he index is 8)
            std::vector<int>::iterator insertionPoint = std::lower_bound(mainChain.begin(), upTo, smallerElement);
            size_t insertion_idx = std::distance(mainChain.begin(), insertionPoint);
            mainChain.insert(insertionPoint, smallerElement);
            // below we will move all numbers which are on the right side from the inserted number
            for (size_t t = 0; t < pairCount; ++t)
            {
                if (biggerNumberPosition[t] >= insertion_idx)
                {
                    ++biggerNumberPosition[t];
                }
            }
        }
        last_jacob = current_jacob;
    }
    if (straggler != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }
    vec = mainChain;
}

// =================== ALGORITHM FOR DEQUE ===========================
void PmergeMe::fordJohnsonSort(std::deque<int> &deq)
{
    const size_t n = deq.size();
    if (n < 2)
        return;

    std::deque<std::pair<int, int> > pairs;
    int straggler = -1;
    for (size_t i = 0; i + 1 < n; i += 2)
    {
        if (deq[i] < deq[i + 1])
            pairs.push_back(std::make_pair(deq[i], deq[i + 1])); // (min, max)
        else
            pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
    }
    if (n % 2 != 0)
        straggler = deq.back();
    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        largerElements.push_back(pairs[i].second);
    }
    fordJohnsonSort(largerElements);
    std::deque<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < largerElements.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        { // here is the reason why is dequer much more slower
            if (largerElements[i] == pairs[j].second)
            {
                sortedPairs.push_back(pairs[j]);
                break;
            }
        }
    }
    const size_t pairCount = sortedPairs.size();
    std::deque<int> mainChain;
    std::deque<int> pendChain;
    for (size_t k = 0; k < pairCount; ++k)
    {
        mainChain.push_back(sortedPairs[k].second);
        pendChain.push_back(sortedPairs[k].first);
    }
    if (pairCount > 0)
        mainChain.push_front(pendChain[0]);  // we can use push_front for the deque
    std::deque<size_t> biggerNumberPosition(pairCount, 0);
    if (pairCount > 0)
    {
        for (size_t k = 0; k < pairCount; ++k)
        {
            biggerNumberPosition[k] = k + 1;
        }
    }
    std::deque<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < pendChain.size())
        jacob.push_back(jacob.back() + 2 * jacob[jacob.size() - 2]);
    size_t last_jacob = 1;
    for (size_t i = 2; i < jacob.size(); ++i)
    {
        size_t current_jacob = jacob[i];
        size_t limit = (current_jacob > pendChain.size()) ? pendChain.size() : current_jacob;
        for (size_t pendIndex = limit; pendIndex > last_jacob; --pendIndex)
        {
            const size_t k = pendIndex;
            const int smallerElement = pendChain[pendIndex - 1];
            const size_t partnerIndex = k - 1;
            std::deque<int>::iterator upTo = mainChain.begin() + biggerNumberPosition[partnerIndex];
            std::deque<int>::iterator insertionPoint = std::lower_bound(mainChain.begin(), upTo, smallerElement);
            size_t insertion_idx = std::distance(mainChain.begin(), insertionPoint);
            mainChain.insert(insertionPoint, smallerElement);
            for (size_t t = 0; t < pairCount; ++t)
            {
                if (biggerNumberPosition[t] >= insertion_idx)
                {
                    ++biggerNumberPosition[t];
                }
            }
        }
        last_jacob = current_jacob;
    }
    if (straggler != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }
    deq = mainChain;
}
