#include "ShrubberyCreationForm.hpp"

ShrubberyCreation::ShrubberyCreation() : AForm("ShrubberyCreationForm", 0, 145, 137)
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException(); 
}

ShrubberyCreation::ShrubberyCreation(const std::string &name, bool flag, int sign, int excut) : AForm(name, flag, sign, excut)
{
   if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException(); 
}

ShrubberyCreation::ShrubberyCreation(const ShrubberyCreation& copie): AForm(copie.GetName(), 0,copie.GetSign(), copie.GetExcut())
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
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