#include"Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm(const std::string &name, int signGrade, int executeGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
    }

AForm::AForm(const AForm &other) 
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}  

AForm::~AForm(){}

AForm& AForm::operator=(const AForm &other){
    if(this != &other){
        _isSigned = other._isSigned;
    }
    return *this;
}

int AForm::getSignGrade() const {
    return _signGrade;
}
int AForm::getExecuteGrade() const {
    return _executeGrade;
}
const std::string &AForm::getName() const {
    return _name;
}  
bool AForm::isSigned() const {
    return _isSigned;
}
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm is not signed!";
}  
const char* AForm::GradeTooLowForExecutionException::what() const throw() {
    return "Bureaucrat's grade is too low for execution!";
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
    os << "AForm Name: " << AForm.getName() 
       << ", Sign Grade: " << AForm.getSignGrade() 
       << ", Execute Grade: " << AForm.getExecuteGrade() 
       << ", Is Signed: " << (AForm.isSigned() ? "Yes" : "No");
    return os;
}
