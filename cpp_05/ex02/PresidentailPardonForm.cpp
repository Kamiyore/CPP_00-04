#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Presidential Pardon Form", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if(this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}
const std::string &PresidentialPardonForm::getTarget() const {
    return _target;
}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowForExecutionException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
