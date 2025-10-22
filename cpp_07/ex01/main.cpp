#include <string>
#include "iter.hpp"

template<typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

void addOne(int& number) {
    number++;
}

void toUpperCase(char& c) {
    c = std::toupper(c);
}

void addSuffix(std::string& str) {
    str += "_X";
}

int main(void) {

    std::cout << "Int test" << std::endl;
    int intArray[] = {0, 1, 2, 3, 4};
    size_t intArrayLength = 5;
    
    std::cout << "Origin: ";
    ::iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;
    
    ::iter(intArray, intArrayLength, addOne);
    
    std::cout << "After changing (+1): ";
    ::iter(intArray, intArrayLength, printElement<int>);
    std::cout << "\n" << std::endl;


    std::cout << "Char test" << std::endl;
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrayLength = 5;

    std::cout << "Origin: ";
    ::iter(charArray, charArrayLength, printElement<char>);
    std::cout << std::endl;

    ::iter(charArray, charArrayLength, toUpperCase);

    std::cout << "Upper letters: ";
    ::iter(charArray, charArrayLength, printElement<char>);
    std::cout << "\n" << std::endl;

        std::cout << "String Test" << std::endl;
    std::string strArray[] = {"one", "two", "three"};
    size_t strArrayLength = 3;

    std::cout << "Origin: ";
    ::iter(strArray, strArrayLength, printElement<std::string>);
    std::cout << std::endl;

    ::iter(strArray, strArrayLength, addSuffix);

    std::cout << "After: ";
    ::iter(strArray, strArrayLength, printElement<std::string>);
    std::cout << "\n" << std::endl;
    return 0;

    std::cout << "Const test: " << std::endl;
    const int constIntArray[] = {100, 200, 300};
    size_t constIntArrayLength = 3;
    
    ::iter(constIntArray, constIntArrayLength, printElement<int>);
    std::cout << std::endl;


}
