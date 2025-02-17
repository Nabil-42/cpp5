#include "Form.hpp"

Form::Form() : _name("Unamed"), _flag(0), _sign(0), _excut(0)
{
    
}

Form::Form(const std::string name, bool flag, const int sign, const int excut) : _name(name), _flag(flag), _sign(sign), _excut(excut)
{

}

Form::Form(const Form& copie): _name(copie._name), _flag(copie._flag), _sign(copie._sign), _excut(copie._excut)
{

}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _flag = other._sign;
    }

    return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high sorry !";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low sorry !";
}