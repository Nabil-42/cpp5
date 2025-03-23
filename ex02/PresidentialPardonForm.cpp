#include "PresidentialPardonForm.hpp"

PresidentalPardon::PresidentalPardon() : AForm("PresidentalPardonForm", 0, 25, 5)
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException(); 
}

PresidentalPardon::PresidentalPardon(const std::string &name) : AForm(name, 0, 25, 5)
{
   if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException(); 
}

PresidentalPardon::PresidentalPardon(const PresidentalPardon& copie): AForm(copie.GetName(), 0,copie.GetSign(), copie.GetExcut())
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException();
}

PresidentalPardon& PresidentalPardon::operator=(const PresidentalPardon &other)
{
    if (this != &other)
    {
    
    }

    return *this;
}

 PresidentalPardon::~PresidentalPardon()
 {

 }

 void  PresidentalPardon::execute(const Bureaucrat &executor) const
 {
    (void)executor;
 }
