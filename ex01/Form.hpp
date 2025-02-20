#ifndef FORM_HPP
#define FORM_HPP
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _flag;
        const int _sign;
        const int _excut;

    public:
    Form();
    Form(const std::string name, bool flag, const int sign, const int execut);
    Form(const Form &copie);
    Form& operator=(const Form& other);
    ~Form();
    
    const std::string GetName();
    bool GetFlag();
    int GetSign();
    int GetExcut();
    void beSigned(Bureaucrat &bureau);

    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

    friend std::ostream &operator<<(std::ostream &os, Form &a);

};

std::ostream &operator<<(std::ostream &os, Form &a);

#endif