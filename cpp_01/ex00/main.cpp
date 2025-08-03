#include "Zombie.hpp"

int main()
{
    //allocates on heap
    Zombie* heapZ = newZombie("Pipi");
    heapZ->announce(); 
    delete heapZ;
    
    //allocates on stack
    randomChump("Koko");
    return 0;
}
