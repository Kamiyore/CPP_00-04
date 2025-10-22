#include "Span.hpp"

Span::Span(): _n(0), _storage(0){}

Span::Span(const unsigned int& n): _n(n), _storage(0){
    _storage.reserve(n);
}

Span::Span(const Span& other){
    _n = other._n;
    _storage = other._storage;
}

Span& Span::operator=(const Span& other){
    if(this != &other){
        _n = other._n;
        _storage = other._storage;
    }
    return (*this);
}

Span::~Span(){}

void Span::addNumber(int number){
    if(_storage.size() >= _n) 
        throw std::runtime_error("Span is full");
    _storage.push_back(number);
}

int Span::shortestSpan(){
    if(_storage.size() == 0 || _storage.size() < 2)
        throw std::runtime_error("Cannot compare because of the lack of numbers.\n");
    std::vector<int> copy = _storage;
    std::sort(copy.begin(), copy.end());
    int minimum = copy[1] - copy[0];
    for(size_t i = 2; i < copy.size(); i++){
        int current = copy[i] - copy[i-1];
        if(current < minimum)
            minimum = current;
    }
    return minimum;
}

int Span::longestSpan(){
    if(_storage.size() == 0 || _storage.size() < 2)
        throw std::runtime_error("Cannot compare because of the lack of numbers.\n");
    int max = *std::max_element(_storage.begin(), _storage.end());
    int min = *std::min_element(_storage.begin(), _storage.end());
 return max - min;
}

