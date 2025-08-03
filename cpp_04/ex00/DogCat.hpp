#ifndef DOGCAT_HPP
#define DOGCAT_HPP
#include "Animal.hpp"

class Dog : public Animal
{
    public:
    Dog();
    Dog(std::string _type);
    Dog& operator= (const Dog& original);
    Dog(const Dog& original);
    ~Dog();
    void makeSound() const;   

};

class Cat : public Animal
{
    public:
    Cat();
    Cat(std::string _type);
    Cat& operator= (const Cat& original);
    Cat(const Cat& original);
    ~Cat();
    void makeSound() const;   

};
#endif
