#include "Weapon.hpp"
#include "HumanB.hpp"
void HumanB::attack()
{
    if (_Weapon)
         std::cout<< _name << " attacks with their " << _Weapon->getType() << std::endl;
    else
        std::cout<< _name<<" has no weapon" << std::endl;
   
}
HumanB::HumanB(const std::string& name)
{
    _name = name;
    _Weapon = 0;
}

void HumanB::setWeapon(Weapon& weapon)
{
    _Weapon = &weapon;

}