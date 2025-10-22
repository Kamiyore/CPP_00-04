#include "Base.hpp"
#include <iostream>
#include "ClassABC.hpp"
#include <cstdlib>

Base * generate(void)
{
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    if(dynamic_cast<A*>(p))
        std::cout<< "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout<< "B" << std::endl;
    else if(dynamic_cast<C*>(p))

        std::cout<< "C" << std::endl;
    else
        std::cout<< "Unknown type" << std::endl;

}

//DYNAMIC_CAST returns reference for the object, but this time we dont care what it returns, we just want to know if it throws an exception or not
// Reference is always an eixisting object, so itc cannot be NULL
// if the cast fails on a reference, it throws std::bad_cast exception, if he fails on a pointer, it returns NULL
void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception& e){}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::exception& e) {}
    std::cout << "C" << std::endl;
}

int main() {
    srand(time(NULL));

    Base* myObject = generate();

    std::cout << "--- Identifying with pointer ---" << std::endl;
    identify(myObject);

    std::cout << "--- Identifying with reference ---" << std::endl;
    identify(*myObject);
    delete myObject;
    return 0;
}
