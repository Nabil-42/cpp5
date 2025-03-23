#ifndef ROBOTOMY
#define ROBOTOMY
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequest : public AForm
{
    private:

    public:
    RobotomyRequest();
    RobotomyRequest(const std::string &name);
    RobotomyRequest(const RobotomyRequest &copie);
    RobotomyRequest& operator=(const RobotomyRequest &other);
    ~RobotomyRequest();

    void execute(const Bureaucrat &executor) const;
    
};


#endif