#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}
//REINTEPRET_CAST is used for low-level reinterpreting of bit patterns. It can cast a pointer to an integer type and vice versa.
//uintptr_t is an unsigned integer type big enough to be capable of storing a data pointer.
