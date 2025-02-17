#ifndef FORM_HPP
#define FORM_HPP
#include <exception>
#include <iostream>

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

    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };


};

#endif