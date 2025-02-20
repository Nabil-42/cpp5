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

ShrubberyCreation& ShrubberyCreation::operator=(const ShrubberyCreation &other)
{
    if (this != &other)
    {

    }
    return *this;
}

 AForm::~AForm()
 {

 }

void ShrubberyCreation::execute(Bureaucrat &bureaucrat)
{
    if(GetFlag() == 1)
    {
        std::fstream fichier("ASCII.txt");
        if (!fichier)
            std::cerr << "Error: Creation fichier ASCII !" << std::endl;
            return;
    }
}


