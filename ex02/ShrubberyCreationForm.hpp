#ifndef SHRUBBERY
#define SHRUBBERY
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreation : public AForm
{
    private:
    std::string _target;

    public:
        ShrubberyCreation();
        ShrubberyCreation(const std::string &name);
        ShrubberyCreation(const ShrubberyCreation &copie);
        ShrubberyCreation& operator=(const ShrubberyCreation &other);
        ~ShrubberyCreation();

        void execute(const Bureaucrat &executor) const;
};


#endif