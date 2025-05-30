#ifndef BUREAUCRAT
#define BUREAUCRAT
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

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

    void signForm(Form &form);

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