#include "AForm.hpp"

AForm::AForm() : _name("Unamed"), _flag(false), _sign(0), _excut(0)
{
    if (_sign > 150 || _excut > 150)
        throw GradeTooLowException();
    if (_sign < 1 || _excut < 1)
        throw GradeTooHighException(); 
}

AForm::AForm(const std::string name, bool flag, const int sign, const int excut) : _name(name), _flag(flag), _sign(sign), _excut(excut)
{
    if (_sign > 150 || _excut > 150)
        throw GradeTooLowException();
    if (_sign < 1 || _excut < 1)
        throw GradeTooHighException(); 
}

AForm::AForm(const AForm& copie): _name(copie._name), _flag(copie._flag), _sign(copie._sign), _excut(copie._excut)
{
    if (_sign > 150 || _excut > 150)
        throw GradeTooLowException();
    if (_sign < 1 || _excut < 1)
        throw GradeTooHighException(); 
}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _flag = other._sign;
    }

    return *this;
}

 AForm::~AForm()
 {

 }

const std::string AForm::GetName() const
{
        return _name;
}
bool AForm::GetFlag()
{
    return _flag;
}

 int AForm::GetSign() const
{
    return _sign;
}

 int AForm::GetExcut() const
{
    return _excut;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high sorry !";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low sorry !";
}

std::ostream &operator<<(std::ostream &os, AForm &a)
{
    os << a._name << ", Grade requirement to sign: "
        << a._sign << ". Grade required to execute: " << a._excut;
    return os;
}

void AForm::beSigned(Bureaucrat &bureau)
{
    if (bureau.GetGrade() <= AForm::_sign)
        {
            _flag = true;   
        }
}