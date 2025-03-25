#ifndef PRESIDENT
#define PRESIDENT
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentalPardon : public AForm
{
    private:
    std::string _target;

    public:
    PresidentalPardon();
    PresidentalPardon(const std::string &name);
    PresidentalPardon(const PresidentalPardon &copie);
    PresidentalPardon& operator=(const PresidentalPardon &other);
    ~PresidentalPardon();

    void execute(const Bureaucrat &executor) const;

};


#endif