#ifndef INTERN
#define INTERN

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:

    public:
    Intern();
    Intern(const Intern& copie);
    Intern& operator=(const Intern &other);
    ~Intern();

    AForm* makeForm(const std::string &name, const std::string &target);
};

#endif