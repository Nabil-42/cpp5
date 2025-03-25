#include "ShrubberyCreationForm.hpp"

ShrubberyCreation::ShrubberyCreation() : AForm("ShrubberyCreationForm", 0, 145, 137)
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException(); 
    _target = "unkwon";
}

ShrubberyCreation::ShrubberyCreation(const std::string &name): AForm("ShrubberyCreationForm", false, 145, 137)
{
   if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException();
     _target = name;
}

ShrubberyCreation::ShrubberyCreation(const ShrubberyCreation& copie): AForm(copie.GetName(), 0,copie.GetSign(), copie.GetExcut())
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException();
    _target = copie._target;
}

ShrubberyCreation& ShrubberyCreation::operator=(const ShrubberyCreation &other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return *this;
}

ShrubberyCreation::~ShrubberyCreation()
 {

 }

void ShrubberyCreation::execute(const Bureaucrat &bureaucrat) const
{
    std::string filename = this->_target + "_shrubbery.txt";
    std::ofstream file(filename.c_str(), std::ios::app);
    if (!file)
    {
        std::cerr << "Error: Creation fichier ASCII !" << std::endl;
        return;
    }
    if(GetFlag() != 1 )
    {
        std::cerr << "Form not signed !";
        file.close();
        return;
    }
    if (bureaucrat.GetGrade() < this->GetExcut())
    {

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
        std::cout << this->_target << "_shrubbery created with beautiful trees!" << std::endl;
    }
    else {
        throw GradeTooLowException();
    }
}


