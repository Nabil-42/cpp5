#include "ShrubberyCreationForm.hpp"

ShrubberyCreation::ShrubberyCreation() : AForm("ShrubberyCreationForm", 0, 145, 137)
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException(); 
}

ShrubberyCreation::ShrubberyCreation(const std::string &name) : AForm(name, false, 145, 137)
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

ShrubberyCreation::~ShrubberyCreation()
 {

 }

void ShrubberyCreation::execute(const Bureaucrat &bureaucrat)
{
    (void)bureaucrat;
    std::fstream file("target_shrubbery.txt");
    if (!file)
    {
        std::cerr << "Error: Creation fichier ASCII !" << std::endl;
        return;
    }
    if(GetFlag() != 1)
    {
        file.close();
        return;
    }
    SetFlag();

    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "       // \\\\" << std::endl;

    file.close();
    std::cout << _target << "_shrubbery created with beautiful trees!" << std::endl;
}


