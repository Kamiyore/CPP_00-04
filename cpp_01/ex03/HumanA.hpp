#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include "HumanB.hpp"

class HumanA
{
    private:
    std:: string _name;
    Weapon& _Weapon;
    public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack();
};
#endif
