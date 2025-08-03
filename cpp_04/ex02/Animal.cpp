#include "Animal.hpp"
#include "DogCat.hpp"
#include "Brain.hpp"

Animal::Animal() : _type("")
{
    std::cout<< "Default constructor for animal called"<< "\n";
}
Animal::Animal(std::string type)
{
    _type = type;
    std::cout<< "Constructor(_type) for animal called"<< "\n";
}
Animal::Animal(const Animal& original) : _type(original._type)
{
    std::cout<< "Copy constructor for animal called"<< "\n";
}
Animal& Animal::operator= (const Animal& original)
{
    
    if(this != &original)
        this->_type = original._type;
    std::cout<< "Assigment operator for animal called"<< "\n";
    return *this;
}
Animal:: ~Animal()
{
    std::cout<< "Destructor for animal called"<< std::endl;
}

void Animal:: makeSound() const
{
    std::cout<< "This is animal's make sound function!"<< "\n";
}
std::string Animal::getType() const
{
    return this->_type;
}
