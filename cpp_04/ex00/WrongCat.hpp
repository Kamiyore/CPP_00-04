#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "Animal.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
    WrongCat();
    WrongCat(std::string _type);
    WrongCat& operator= (const WrongCat& original);
    WrongCat(const WrongCat& original);
    ~WrongCat();
    void makeSound() const;   

};
#endif
