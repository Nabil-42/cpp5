#include "Form.hpp"

Form::Form() : _name("Form"), _flag(false), _sign(0), _excut(0)
{
    if (_sign > 150 || _excut > 150)
        throw GradeTooLowException();
    if (_sign < 1 || _excut < 1)
        throw GradeTooHighException(); 
}

Form::Form(const std::string name, bool flag, const int sign, const int excut) : _name(name), _flag(flag), _sign(sign), _excut(excut)
{
    if (_sign > 150 || _excut > 150)
        throw GradeTooLowException();
    if (_sign < 1 || _excut < 1)
        throw GradeTooHighException(); 
}

Form::Form(const Form& copie): _name(copie._name), _flag(copie._flag), _sign(copie._sign), _excut(copie._excut)
{
    if (_sign > 150 || _excut > 150)
        throw GradeTooLowException();
    if (_sign < 1 || _excut < 1)
        throw GradeTooHighException(); 
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _flag = other._sign;
    }

    return *this;
}

 Form::~Form()
 {

 }

const std::string Form::GetName()
{
        return _name;
}
bool Form::GetFlag()
{
    return _flag;
}

 int Form::GetSign()
{
    return _sign;
}

 int Form::GetExcut()
{
    return _excut;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high sorry !";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low sorry !";
}

std::ostream &operator<<(std::ostream &os, Form &a)
{
    os << a._name << ", Grade requirement to sign: "
        << a._sign << ". Grade required to execute: " << a._excut;
    return os;
}

void Form::beSigned(Bureaucrat &bureau)
{
    if (bureau.GetGrade() <= Form::_sign)
        {
            _flag = true;   
        }
}