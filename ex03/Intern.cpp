#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& copie)
{
    (void)copie;
}

Intern& Intern::operator=(const Intern &other)
{
    if (this != &other)
    {

    }
    return *this;
}

Intern::~Intern()
{

}

AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string tab[3] = {"PresidentialPardonForm","RobotomyPardonForm","ShrubberyCreationForm"};

    AForm* (*formCreators[3])(std::string const&) = {
        &PresidentialPardon::create,
        &RobotomyRequest::create,
        &ShrubberyCreation::create
    };

    for(int i = 0; i < 3; ++i)
    {
        if (tab[i] == name)
            {
             std::cout << "Intern creates " << name << std::endl;
             return formCreators[i](target);   
            }   
    }
    std::cout << "Form type " << name << " not found." << std::endl;
    return NULL;
}