#include "Zombie.hpp"

int main(void)
{
    int N = 6;
    int i= 0;

    Zombie* horde = zombieHorde(6,"Popo");
    while(i != N && horde !=NULL)
    {
        horde->announce();
        i++;
    }
    delete[] horde;
    return 0;
}
