#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Constructor called." << "\n";
}
ClapTrap:: ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Constructor(name) called." << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& original) :_name(original._name), _hit_points(original._hit_points),_energy_points(original._energy_points), _attack_damage(original._attack_damage)
{
    
    std::cout<< "Copy constructor called"<< "\n";
}
ClapTrap::~ClapTrap()
{
    std::cout<< "Destructor called"<< std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& original)
{
    if (this == &original)
        return *this;        // just for safety
     _name = original._name;
    _hit_points = original._hit_points;
    _attack_damage = original._attack_damage;
    _energy_points = original._energy_points;
    std::cout<< "Assignment operator called"<< "\n";
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if(this->_hit_points > 0 && this->_energy_points > 0)
    {
        std::cout<< "ClapTrap "<<_name<< " attacks " <<target<<", causing "<< _attack_damage <<"points of damage!" << "\n";
        this->_energy_points--;
    }
    else
     std::cout<< "Hit points or Energy points are 0!"<< "\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
    _hit_points -= amount;
    if(_hit_points < 0)
        _hit_points = 0;
   std::cout << _name << " takes " << amount << " of damage. " << _hit_points << " is remaining"<<"\n";     
}

void ClapTrap::beRepaired(unsigned int amount)
{

    if(_energy_points == 0)
    {
        std::cout<< "Not enough energy points!"<< "\n";
        return;
    }
    else if (_hit_points == 0)
    {
        std::cout<< "Not enough hit points!"<< "\n";
        return;
    }
    else if(_energy_points != 0 && _hit_points != 0 )
    {
        _hit_points += amount;
        _energy_points--;
        std::cout << _name << " repairs itself by " << amount << " points! Energy points left: " << _energy_points << " Hit points are now: " << _hit_points << "\n";
    }
}
