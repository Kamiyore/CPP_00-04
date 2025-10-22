#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

class Span{
    private:
        unsigned int _n;
        std::vector<int> _storage;
    public:
        Span();
        Span(const unsigned int& n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int number);
        template <typename InputIterator>
        void addNumber(InputIterator first, InputIterator last);
        int shortestSpan();
        int longestSpan();
};

template <typename InputIterator>
void Span::addNumber(InputIterator first, InputIterator last){
    size_t count = std::distance(first,last);
    if(_storage.size() + count > _n)
        throw std::runtime_error("Cannot add numbers, Span would overflow.");
    _storage.insert(_storage.end(), first, last);
}

#endif
