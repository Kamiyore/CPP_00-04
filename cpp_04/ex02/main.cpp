#include "Animal.hpp"
#include "DogCat.hpp"
#include "Brain.hpp"

// int main()
// {
//     Animal test;
//     return 0;
// }

int main()
{
// const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound(); //dog sound
// meta->makeSound();
// delete meta;
delete j;
delete i;
}

// int main()
// {
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// delete j; //should not create a leak
// delete i;

//     std::cout << "\n--- Test 1: Deep Copy via Copy Constructor (Dog) ---" << std::endl;
//     {

//         Dog originalDog;
//         std::cout << "Original Dog's Brain address: " << originalDog.getBrain() << std::endl;

//         Dog copiedDog = originalDog;
//         std::cout << "Copied Dog's Brain address: " << copiedDog.getBrain() << std::endl;

//         if (originalDog.getBrain() != copiedDog.getBrain()) {
//             std::cout << "--> Addresses of Brains are different. Deep copy allocation confirmed for copy constructor!" << std::endl;
//         } else {
//             std::cout << "--> Addresses of Brains are the SAME. Error: Shallow copy of Brain pointer for copy constructor!" << std::endl;
//         }
//     } 

//     std::cout << "\n--- Test 2: Deep Copy via Assignment Operator (Cat) ---" << std::endl;
//     {
//         Cat sourceCat;
//         Cat targetCat;

//         std::cout << "Source Cat's Brain address (before assignment): " << sourceCat.getBrain() << std::endl;
//         std::cout << "Target Cat's Brain address (before assignment): " << targetCat.getBrain() << std::endl;

//         targetCat = sourceCat;

//         std::cout << "Source Cat's Brain address (after assignment): " << sourceCat.getBrain() << std::endl;
//         std::cout << "Target Cat's Brain address (after assignment): " << targetCat.getBrain() << std::endl;

//         if (sourceCat.getBrain() != targetCat.getBrain()) {
//             std::cout << "--> Addresses of Brains are different. Deep copy allocation confirmed for assignment operator!" << std::endl;
//         } else {
//             std::cout << "--> Addresses of Brains are the SAME. Error: Shallow copy of Brain pointer for assignment operator!" << std::endl;
//         }
//     } 

//     std::cout << "\n--- 3. Subject Requirement: Array of Animals ---" << std::endl;
//     const int num_animals = 10;
//     Animal* zoo[num_animals];

//     for (int i = 0; i < num_animals / 2; ++i) {
//         std::cout << "Creating Dog " << i << std::endl;
//         zoo[i] = new Dog();
//     }
//     for (int i = num_animals / 2; i < num_animals; ++i) {
//         std::cout << "Creating Cat " << i << std::endl;
//         zoo[i] = new Cat();
//     }

//     std::cout << "\n--- Making sounds ---" << std::endl;
//     for (int i = 0; i < num_animals; ++i) {
//         zoo[i]->makeSound();
//     }

//     std::cout << "\n--- Deleting Animals from array ---" << std::endl;
//     for (int i = 0; i < num_animals; ++i) {
//         delete zoo[i];
//     }
//     return 0;
// }

