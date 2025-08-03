#include "Animal.hpp"
#include "DogCat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
    std::cout<< "Default constructor for wronganimal called"<< "\n";
}
WrongAnimal::WrongAnimal(std::string type)
{
    _type = type;
    std::cout<< "Constructor(_type) for wronganimal called"<< "\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal& original) : _type(original._type)
{
    std::cout<< "Copy constructor for wronganimal called"<< "\n";
}
WrongAnimal& WrongAnimal::operator= (const WrongAnimal& original)
{
    
    if(this != &original)
        this->_type = original._type;
    std::cout<< "Assigment operator for wronganimal called"<< "\n";
    return *this;
}
WrongAnimal:: ~WrongAnimal()
{
    std::cout<< "Destructor for wronganimal called"<< std::endl;
}

void WrongAnimal:: makeSound() const
{
    std::cout<< "This is wronganimal's make sound function!"<< "\n";
}
std::string WrongAnimal::getType() const
{
    return this->_type;
}
