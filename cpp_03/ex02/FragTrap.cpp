#include"ScavTrap.hpp"
#include"FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default FragTrap")
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap Default constructor called for " << this->_name << "!" << "\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap constructor "<< _name << " called." << "\n";
}

FragTrap::FragTrap(const FragTrap& original) : ClapTrap(original)
{
    
    std::cout<< "FragTrap copy constructor called"<< "\n";
}

FragTrap& FragTrap::operator= (const FragTrap& original)
{
    if (this == &original)
        return *this;       // just for safety
    ClapTrap::operator=(original);

    std::cout<< "FragTrap assignment operator called"<< "\n";
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout<< "FragTrap Destructor called"<< std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if(this->_hit_points > 0 && this->_energy_points > 0)
    {
        std::cout<< "FragTrap "<<_name<< " attacks " <<target<<", causing "<< _attack_damage <<"points of damage!" << "\n";
        this->_energy_points--;
    }
    else
     std::cout<< "Hit points or Energy points are 0!"<< "\n";
}
void FragTrap::highFivesGuys(void)
{
      std::cout << "FragTrap " << this->_name << " requests a high-five! 🙌 Give me some love, guys!" << "\n";
}
