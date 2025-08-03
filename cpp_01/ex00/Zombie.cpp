#include "Zombie.hpp"

Zombie::Zombie(const std::string& name)
{
    _name = name;
}
Zombie::~Zombie()
{
    std::cout <<  this->_name << " is destroyed" << std::endl;
}
void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}
