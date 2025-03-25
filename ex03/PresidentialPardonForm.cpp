#include "PresidentialPardonForm.hpp"

PresidentialPardon::PresidentialPardon() : AForm("PresidentialPardonForm", 0, 25, 5)
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException();
    _target = "unknow";
}

PresidentialPardon::PresidentialPardon(const std::string &name) : AForm("PresidentialPardonForm", 0, 25, 5)
{
   if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException();
    _target = name; 
}

PresidentialPardon::PresidentialPardon(const PresidentialPardon& copie): AForm(copie.GetName(), 0,copie.GetSign(), copie.GetExcut())
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException();
    _target = copie._target;
}

PresidentialPardon& PresidentialPardon::operator=(const PresidentialPardon &other)
{
    if (this != &other)
    {
        _target = other._target;
    }

    return *this;
}

 PresidentialPardon::~PresidentialPardon()
 {

 }

 void  PresidentialPardon::execute(const Bureaucrat &executor) const
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

AForm* PresidentialPardon::create(std::string const& target)
{
    return new PresidentialPardon(target);
}