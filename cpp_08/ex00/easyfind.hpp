#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
void easyfind(const T& container, int value_to_find ){
    typename T::const_iterator it = std::find(container.begin(), container.end(), value_to_find);
    if(it == container.end())
        throw std::runtime_error("Value not found in the container.");
    std::cout << "Value found: " << *it << std::endl;
}
#endif
