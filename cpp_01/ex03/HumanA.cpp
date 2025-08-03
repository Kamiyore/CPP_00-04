#include "Weapon.hpp"
#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout<< _name << " attacks with their "<< _Weapon.getType() <<std::endl;
}

HumanA::HumanA(const std::string& name, Weapon& weapon)
: _name(name) 
, _Weapon(weapon)
{}

/*member initializer list*/