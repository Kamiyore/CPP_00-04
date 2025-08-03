#include"ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_ScavTrap")
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap Default constructor called for " << this->_name << "!" << "\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap constructor "<< _name << " called." << "\n";
}

ScavTrap::ScavTrap(const ScavTrap& original) : ClapTrap(original)
{
    
    std::cout<< "ScavTrap copy constructor called"<< "\n";
}

ScavTrap& ScavTrap::operator= (const ScavTrap& original)
{
    if (this == &original)
        return *this;       // just for safety
    ClapTrap::operator=(original);

    std::cout<< "ScavTrap assignment operator called"<< "\n";
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout<< "ScavTrap Destructor called"<< std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(this->_hit_points > 0 && this->_energy_points > 0)
    {
        std::cout<< "ScavTrap "<<_name<< " attacks " <<target<<", causing "<< _attack_damage <<"points of damage!" << "\n";
        this->_energy_points--;
    }
    else
     std::cout<< " ScavTrp's hit points or energy points are 0!"<< "\n";
}
int ScavTrap::getEnergyPoints()const
{
    return _energy_points;
}
void ScavTrap:: guardGate()
{
    std::cout<< "ScavTrap is now in Gate keeper mode."<< "\n";
}
