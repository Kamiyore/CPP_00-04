#include "Animal.hpp"
#include "DogCat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound(); //dog sound
meta->makeSound();
delete meta;
delete j;
delete i;

std::cout << std::endl;
std::cout << std::endl;

// with wrong animal
const WrongAnimal* metawrong = new WrongAnimal();
const WrongAnimal* w = new WrongCat();
std::cout << w->getType() << " " << std::endl;
w->makeSound();
metawrong->makeSound();
delete metawrong;
delete w;

std::cout << std::endl;
std::cout << std::endl;

 std::cout << "\n--- Test 1: Dynamic Polymorphism with Array of Pointers ---" << std::endl;
    {
        Animal* zoo[6];

        zoo[0] = new Dog();
        zoo[1] = new Cat();
        zoo[2] = new Animal();
        zoo[3] = new Dog();
        zoo[4] = new Cat();
        zoo[5] = new Animal();

        std::cout << "\n--- Animal sounds in the zoo ---" << std::endl;
        for (int k = 0; k < 6; ++k)
        {
            std::cout << "Animal " << k << " (Type: " << zoo[k]->getType() << "): ";
            zoo[k]->makeSound();
        }
        std::cout << "\n--- Destructing zoo animals ---" << std::endl;
        for (int k = 0; k < 6; ++k)
            delete zoo[k];
    }
    return 0;
}
