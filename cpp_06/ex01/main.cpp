#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"

int main() {

    Data myData;
    myData.s1 = "Hello";
    myData.n = 42;
    myData.s2 = "World";

    Data* originalPtr = &myData;

    std::cout << "Original Pointer Address:  " << originalPtr << std::endl;
    std::cout << "Data content: s1=" << originalPtr->s1 << ", n=" << originalPtr->n << ", s2=" << originalPtr->s2 << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "Serialized to uintptr_t:   " << raw << std::endl;
    
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized Pointer Addr: " << deserializedPtr << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    if (originalPtr == deserializedPtr) {
        std::cout << "✅ SUCCESS: Pointers are the same." << std::endl;
        std::cout << "Data content via new pointer: s1=" << deserializedPtr->s1 << ", n=" << deserializedPtr->n << ", s2=" << deserializedPtr->s2 << std::endl;
    } else {
        std::cout << "❌ FAILURE: Pointers do not match." << std::endl;
    }


    std::cout << "\n=== Second example with dynamic allocation) ===" << std::endl;
    Data* anotherPtr = new Data;
    anotherPtr->s1 = "Testing";
    anotherPtr->n = 1337;
    anotherPtr->s2 = "Heap";

    std::cout << "Original Pointer Address:  " << anotherPtr << std::endl;
    std::cout << "Data content: s1=" << anotherPtr->s1 << ", n=" << anotherPtr->n << ", s2=" << anotherPtr->s2 << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    
    uintptr_t anotherRaw = Serializer::serialize(anotherPtr);
    std::cout << "Serialized to uintptr_t:   " << anotherRaw << std::endl;
    Data* anotherDeserializedPtr = Serializer::deserialize(anotherRaw);
    std::cout << "Deserialized Pointer Addr: " << anotherDeserializedPtr << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    if (anotherPtr == anotherDeserializedPtr) {
        std::cout << "✅ SUCCESS: Pointers are the same." << std::endl;
        std::cout << "Data content via new pointer: s1=" << anotherDeserializedPtr->s1 << ", n=" << anotherDeserializedPtr->n << ", s2=" << anotherDeserializedPtr->s2 << std::endl;
    } else {
        std::cout << "❌ FAILURE: Pointers do not match." << std::endl;
    }
    delete anotherPtr;

    return 0;
}
