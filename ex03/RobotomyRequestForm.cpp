#include "RobotomyRequestForm.hpp"

RobotomyRequest::RobotomyRequest() : AForm("RobotomyRequestForm", 0, 72, 45)
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException(); 
    _target = "unkwon";
}

RobotomyRequest::RobotomyRequest(const std::string &name) : AForm("RobotomyRequestForm", 0, 72, 45)
{
   if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException();
    _target = name;

}

RobotomyRequest::RobotomyRequest(const RobotomyRequest& copie): AForm(copie.GetName(), 0,copie.GetSign(), copie.GetExcut())
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException();
    _target = copie._target;
}

RobotomyRequest& RobotomyRequest::operator=(const RobotomyRequest &other)
{
    if (this != &other)
    {
        _target = other._target;
    }

    return *this;
}

 RobotomyRequest::~RobotomyRequest()
 {

 }

 void  RobotomyRequest::execute(const Bureaucrat &executor) const
 {
    if (this->GetFlag() == 0)
        return (std::cerr << "Form not signed, The robotomy failed." << std::endl, (void)0);
    if (this->GetFlag() == 1 && executor.GetGrade() < this->GetExcut())
        std::cout << "Bzzz Bzzz Bzzz " << this->_target 
        << " has been robotomized successfully 50% of the time."
        << std::endl;
    else 
    {
        std::cout << "The robotomy failed." << std::endl;
        throw GradeTooLowException();
    }
 }

 AForm* RobotomyRequest::create(std::string const& target)
{
    return new RobotomyRequest(target);
}