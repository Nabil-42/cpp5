#ifndef AFORM_HPP
#define AFORM_HPP
#include <exception>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _flag;
        const int _sign;
        const int _excut;

    public:
    AForm();
    AForm(const std::string name, bool flag, const int sign, const int execut);
    AForm(const AForm &copie);
    AForm& operator=(const AForm& other);
    ~AForm();

    const std::string GetName() const;
    bool GetFlag() const;
    void SetFlag();
    int GetSign() const;
    int GetExcut() const;
    void beSigned(Bureaucrat &bureau);

    virtual void execute(const Bureaucrat &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

    friend std::ostream &operator<<(std::ostream &os, AForm &a);

};

std::ostream &operator<<(std::ostream &os, AForm &a);

#endif