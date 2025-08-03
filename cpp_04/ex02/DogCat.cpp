#include "Animal.hpp"
#include "DogCat.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog")
{
    _brain = new Brain();
    std::cout<< "Default constructor for 🐕 called"<< std::endl;
}
Dog::Dog(std::string type) : Animal(type)
{
    _brain = new Brain();
    std::cout<< "Constructor(_type) for 🐕 called"<< std::endl;
}
Dog::Dog(const Dog& original) : Animal(original), _brain(new Brain(*(((original._brain)))))
{
    std::cout<< "Copy constructor for 🐕 called"<< std::endl;
}
Dog& Dog::operator= (const Dog& original)
{
    
    if(this != &original)
    {
        Animal::operator=(original);
        delete _brain;
        _brain = new Brain(*(original._brain));
    }
    std::cout<< "Assigment operator for 🐕 called"<< std::endl;
    return *this;
}
Dog:: ~Dog()
{
    delete _brain;
    std::cout<< "Destructor for 🐕 called"<< std::endl;
}
void Dog::makeSound() const
{
    std::cout << "Woof, Woof"<< "\n";
}

Brain* Dog::getBrain() const
{
    return _brain;
}

//////////////////////////////////////////////////////////////////////////////////////


Cat::Cat() : Animal("Cat")
{
    _brain = new Brain();
    std::cout<< "Default constructor for 😺 called"<< std::endl;
}
Cat::Cat(std::string type) : Animal(type)
{
    _brain = new Brain();
    std::cout<< "Constructor(_type) for 😺 called"<< std::endl;
}
Cat::Cat(const Cat& original) : Animal(original), _brain(new Brain(*(((original._brain)))))
{
    std::cout<< "Copy constructor for 😺 called"<< std::endl;
}
Cat& Cat::operator= (const Cat& original)
{
    
    if(this != &original)
    {
        Animal::operator=(original);
        delete _brain;
        _brain = new Brain(*(original._brain));
    }
        
    std::cout<< "Assigment operator for 😺 called"<< std::endl;
    return *this;
}
Cat:: ~Cat()
{
    delete _brain;
    std::cout<< "Destructor for 😺 called"<< std::endl;
}
void Cat::makeSound() const
{
    std::cout << "Meow, meow"<< "\n";
}

Brain* Cat::getBrain() const
{
    return _brain;
}
