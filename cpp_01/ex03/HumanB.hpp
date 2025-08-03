#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include "HumanA.hpp"
class HumanB
{
    private:
    Weapon* _Weapon;
    std:: string _name;
    public:
    HumanB(const std::string& name);
    void setWeapon(Weapon& weapon);
    void attack();
};
#endif