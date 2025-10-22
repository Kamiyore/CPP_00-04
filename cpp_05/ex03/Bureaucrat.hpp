#include <iostream>
#include <string>

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
class AForm;
class Bureaucrat {
    private:
    const std::string _name;
    int _grade;
    
    public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();
    void incrementGrade();
    void decrementGrade();
    const std::string &getName() const;
    int getGrade() const;
    void executeForm(const AForm &form);
    void signForm(AForm &form);
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
