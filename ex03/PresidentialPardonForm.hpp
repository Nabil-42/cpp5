#ifndef PRESIDENT
#define PRESIDENT
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardon : public AForm
{
    private:
    std::string _target;
    
    public:
    PresidentialPardon();
    PresidentialPardon(const std::string &name);
    PresidentialPardon(const PresidentialPardon &copie);
    PresidentialPardon& operator=(const PresidentialPardon &other);
    ~PresidentialPardon();

    void execute(const Bureaucrat &executor) const;
    static AForm* create(std::string const& target);
};  


#endif