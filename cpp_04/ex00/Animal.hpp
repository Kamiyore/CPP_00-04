#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal
{
    protected:
    std::string _type;

    public:
    Animal();
    Animal(std::string _type);
    Animal(const Animal& original);
    Animal& operator= (const Animal& original);
    virtual ~Animal();
    virtual void makeSound()const;
    std::string getType() const;
};

#endif
