#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

// template < typename T_array, typename T_function>
// void iter(T_array *array, size_t length, T_function function)
// {
// 	for (size_t i = 0; i < length; i++)
// 	{
// 		function(array[i]);
// 	}
// }

template <typename T>
void iter(T* address, size_t length, void (*f)(T &lement)) {
    for (size_t i = 0; i < length; i++) {
        f(address[i]);
    }
}

//const version
template <typename T>
void iter(const T* address, size_t length, void (*f)(const T &lement)) {
    for (size_t i = 0; i < length; i++) {
        f(address[i]);
    }
}


#endif
