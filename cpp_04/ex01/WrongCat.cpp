#include "Animal.hpp"
#include "DogCat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout<< "Default constructor for ❌😺 called"<< std::endl;
}
WrongCat::WrongCat(std::string type) : WrongAnimal("WrongCat")
{
    _type = type;
    std::cout<< "Constructor(_type) for ❌😺 called"<< std::endl;
}
WrongCat::WrongCat(const WrongCat& original) : WrongAnimal(original)
{
    std::cout<< "Copy constructor for ❌😺 called"<< std::endl;
}
WrongCat& WrongCat::operator= (const WrongCat& original)
{
    
    if(this != &original)
        WrongAnimal::operator=(original);
    std::cout<< "Assigment operator for ❌😺 called"<< std::endl;
    return *this;
}
WrongCat:: ~WrongCat()
{
    std::cout<< "Destructor for ❌😺 called"<< std::endl;
}
void WrongCat::makeSound() const
{
    std::cout << "Meeeew, meow"<< "\n";
}
