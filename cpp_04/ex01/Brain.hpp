#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "Animal.hpp"

class Brain
{
    private:
    std::string ideas[100];
    public:
    Brain();
    Brain& operator= (const Brain& original);
    Brain(const Brain& original);
    ~Brain();
};
#endif
