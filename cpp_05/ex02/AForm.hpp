#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _executeGrade;
    public:
        AForm();
        AForm(const std::string &name, int signGrade, int executeGrade);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
        int getSignGrade() const;
        int getExecuteGrade() const;
        const std::string &getName() const;
        bool isSigned() const;
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
        
        class GradeTooHighException : public std::exception{
            public:
            const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
            const char *what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowForExecutionException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
