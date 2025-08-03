#include "Animal.hpp"
#include "DogCat.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout<< "Default constructor for 🐕 called"<< std::endl;
}
Dog::Dog(std::string type) : Animal(type)
{
    std::cout<< "Constructor(_type) for 🐕 called"<< std::endl;
}
Dog::Dog(const Dog& original) : Animal(original)
{
    std::cout<< "Copy constructor for 🐕 called"<< std::endl;
}
Dog& Dog::operator= (const Dog& original)
{
    
    if(this != &original)
        Animal::operator=(original);
    std::cout<< "Assigment operator for 🐕 called"<< std::endl;
    return *this;
}
Dog:: ~Dog()
{
    std::cout<< "Destructor for 🐕 called"<< std::endl;
}
void Dog::makeSound() const
{
    std::cout << "Woof, Woof"<< "\n";
}

//////////////////////////////////////////////////////////////////////////////////////


Cat::Cat() : Animal("Cat")
{
    std::cout<< "Default constructor for 😺 called"<< std::endl;
}
Cat::Cat(std::string type) : Animal(type)
{
    std::cout<< "Constructor(_type) for 😺 called"<< std::endl;
}
Cat::Cat(const Cat& original) : Animal(original)
{
    std::cout<< "Copy constructor for 😺 called"<< std::endl;
}
Cat& Cat::operator= (const Cat& original)
{
    
    if(this != &original)
        Animal::operator=(original);
    std::cout<< "Assigment operator for 😺 called"<< std::endl;
    return *this;
}
Cat:: ~Cat()
{
    std::cout<< "Destructor for 😺 called"<< std::endl;
}
void Cat::makeSound() const
{
    std::cout << "Meow, meow"<< "\n";
}
