#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& original);
    ScavTrap& operator=(const ScavTrap& original);
    ~ScavTrap();
    void attack(const std::string& target);
    int getEnergyPoints()const;
    void guardGate();
};
#endif
