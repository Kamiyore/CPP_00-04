#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout <<  this->_name << " is destroyed" << std::endl;
}
void Zombie::setName(const std::string& name)
{
    this->_name = name;
}
