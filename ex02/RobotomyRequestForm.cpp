#include "RobotomyRequestForm.hpp"

RobotomyRequest::RobotomyRequest() : AForm("RobotomyRequestForm", 0, 72, 45)
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException(); 
}

RobotomyRequest::RobotomyRequest(const std::string &name) : AForm(name, 0, 72, 45)
{
   if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException(); 
}

RobotomyRequest::RobotomyRequest(const RobotomyRequest& copie): AForm(copie.GetName(), 0,copie.GetSign(), copie.GetExcut())
{
    if (AForm::GetSign() > 150 || AForm::GetExcut() > 150)
        throw GradeTooLowException();
    if (AForm::GetSign() < 1 || AForm::GetExcut() < 1)
        throw GradeTooHighException();
}

RobotomyRequest& RobotomyRequest::operator=(const RobotomyRequest &other)
{
    if (this != &other)
    {
        
    }

    return *this;
}

 RobotomyRequest::~RobotomyRequest()
 {

 }

 void  RobotomyRequest::execute(const Bureaucrat &executor) const
 {
    (void)executor;
    if (this->GetFlag() == 1)
        std::cout << "Bzzz Bzzz Bzzz " << this->GetName() 
        << " has been robotomized successfully 50% of the time."
        << std::endl;
    else 
    {
        // std::cout << "The robotomy failed." << std::endl;
        throw(GradeTooLowException());
    }
 }
