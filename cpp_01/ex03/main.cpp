#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
int main()
{
    {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    }
    {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    }

    std::cout<<std::endl;

    {
    Weapon club("crude spiked club");
    HumanA bob("Bob", club);
    HumanB jim("Jim");
    bob.attack();
    jim.attack();
    jim.setWeapon(club);
    jim.attack();
    bob.attack();
    }
    return 0;
}
