#include "Brain.hpp"
#include <sstream>

Brain::Brain()
{
    std::cout<< "Default constructor for 🧠 called"<< "\n"; //onl this is for subject
    for (int i = 0; i < 100; ++i)
    {
        std::stringstream ss;
        ss << i;
        this->ideas[i] = "Idea number " + ss.str() + " from NEW 🧠 .";
    }
}

Brain::Brain(const Brain& original)
{
    std::cout<< "Copy constructor for 🧠  called"<< "\n";
    for(int i = 0; i < 100; i++)
    this->ideas[i] = original.ideas[i];
}
Brain& Brain::operator= (const Brain& original)
{
   std::cout<< "Assigment operator for 🧠  called"<< "\n"; 
    if(this != &original)
        for(int i = 0; i < 100; i++)
            this->ideas[i] = original.ideas[i];
    return *this;
}

Brain:: ~Brain()
{
    std::cout<< "Destructor for 🧠  called"<< std::endl;
}
