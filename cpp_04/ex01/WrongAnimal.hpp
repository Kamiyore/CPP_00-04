#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
    std::string _type;

    public:
    WrongAnimal();
    WrongAnimal(std::string _type);
    WrongAnimal(const WrongAnimal& original);
    WrongAnimal& operator= (const WrongAnimal& original);
    ~WrongAnimal();
    void makeSound()const;
    std::string getType() const;
};

#endif
