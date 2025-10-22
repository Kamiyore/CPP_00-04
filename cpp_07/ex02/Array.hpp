#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
template <typename T>
class Array{
    private:
    T* _array;
    unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array (const Array<T>& obj);
        Array& operator=(const Array<T>& obj);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;

};

#endif

template <typename T>
Array<T>::Array() : _array(NULL), _size(0){}

template <typename T>
Array<T>::Array(unsigned int i) : _size(i) {
    _array = new T[i]();
}

template <typename T>
Array<T>::Array(const Array<T>& obj){
    _size = obj._size;
    _array = new T[_size];
    for(unsigned int i = 0; i < _size; i++){
        _array[i] = obj._array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj){
    if(this != &obj)
    {
        delete[] _array;
        _size = obj._size;
        _array = new T[_size];
        for(unsigned int i = 0; i < _size; i++){
            _array[i] = obj._array[i];
        }
    }
    return(*this);
}

template <typename T>
Array<T>::~Array(){
    delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
    if(index >= _size)
        throw std::exception();
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::exception();
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const{
    return _size;
}
