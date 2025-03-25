#include "PresidentialPardonForm.hpp"

PresidentalPardon::PresidentalPardon() : AForm("PresidentalPardonForm", 0, 25, 5)
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException();
    _target = "unknow";
}

PresidentalPardon::PresidentalPardon(const std::string &name) : AForm("PresidentalPardonForm", 0, 25, 5)
{
   if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException();
    _target = name; 
}

PresidentalPardon::PresidentalPardon(const PresidentalPardon& copie): AForm(copie.GetName(), 0,copie.GetSign(), copie.GetExcut())
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException();
    _target = copie._target;
}

PresidentalPardon& PresidentalPardon::operator=(const PresidentalPardon &other)
{
    if (this != &other)
    {
        _target = other._target;
    }

    return *this;
}

 PresidentalPardon::~PresidentalPardon()
 {

 }

 void  PresidentalPardon::execute(const Bureaucrat &executor) const
 {
    if (this->GetFlag() == 0)
        return (std::cout << "Form not signed", (void)0);
    if (this->GetFlag() == 1 && executor.GetGrade() < this->GetExcut() )
    {
        std::cout << this->_target
        << " has been pardoned by zaphod Beeblebrox !" 
        << std::endl;
    }
    else {
        throw GradeTooLowException();
    }
 }
