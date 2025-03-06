#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Unamed"),  _grade(0)
{
   
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    std::cout << "Constructor bureaucrat check !!" << std::endl;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copie) : _name(copie._name)
{
    _grade = copie._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{

}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low sorry !";
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too High sorry !";
}


const std::string Bureaucrat::GetName()
{
    return _name;
}

int Bureaucrat::GetGrade()
{
    return _grade;
}

void Bureaucrat::IncrementGrade()
{
    if (_grade > 150)
        throw GradeTooLowException();
    if (_grade <= 1)
        throw GradeTooHighException();
    if (_grade != 1)
        _grade--;
}

void Bureaucrat::DecrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade != 150)
        _grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &a)
{
    os << a.GetName() << ", Bureaucrat grade " << a.GetGrade() << ".";
    return os;
}

 void Bureaucrat::signForm(AForm &Aform)
 {
     try{
            Aform.beSigned(*this);
            Aform.execute(*this);
        }
    catch (std::exception &e)   
    {
        std::cout << this->GetName() << " couldn't sign " 
        << Aform.GetName() << " because he has not the grade" << std::endl;
    }
 }
