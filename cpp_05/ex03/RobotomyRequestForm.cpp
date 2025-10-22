#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm:: RobotomyRequestForm() : AForm("Default Robotomy Form", 72, 45), _target("Default") {}

RobotomyRequestForm:: RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm:: RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if(this != &other){
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string &RobotomyRequestForm::getTarget() const {
    return _target;
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowForExecutionException();

    std::cout << "Bzzzz... Drilling noises..." << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy on " << _target << " failed!" << std::endl;
}
