#ifndef BUREAUCRAT
#define BUREAUCRAT
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat 
{
    private:
    const std::string _name;
    int _grade;


    public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& copie);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string GetName();
    int GetGrade();
    void IncrementGrade();
    void DecrementGrade();

    void signForm(AForm &form);
    void executeForm(AForm const & form);

    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    
    class GradeTooHighException : public std::exception 
    {
        public:
            const char *what() const throw();
     };

    friend std::ostream &operator<<(std::ostream &os,  Bureaucrat &a);
};






#endif