#ifndef PRESIDENT
#define PRESIDENT
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreation : public AForm
{
    private:

    public:
    ShrubberyCreation();
    ShrubberyCreation(const std::string &name, bool flag, int _sign, int _excut);
    ShrubberyCreation(const ShrubberyCreation &copie);
    ShrubberyCreation& operator=(const ShrubberyCreation &other);
    ~ShrubberyCreation();

    
};


#endif