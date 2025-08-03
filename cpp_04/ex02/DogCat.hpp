#ifndef DOGCAT_HPP
#define DOGCAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
    Brain* _brain;
    public:
    Dog();
    Dog(std::string _type);
    Dog& operator= (const Dog& original);
    Dog(const Dog& original);
    ~Dog();
    void makeSound() const; 
    Brain* getBrain() const;
};

class Cat : public Animal
{
    private:
    Brain* _brain;
    public:
    Cat();
    Cat(std::string _type);
    Cat& operator= (const Cat& original);
    Cat(const Cat& original);
    ~Cat();
    void makeSound() const; 
    Brain* getBrain() const;
};

#endif
