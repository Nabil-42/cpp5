#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <climits>

int main() {
    try {
        Bureaucrat bob("Bob", 100);
        Bureaucrat alice("Alice", 1);
        
        ShrubberyCreation contract("Contract");
        RobotomyRequest robot ("Human");

        std::cout << contract << std::endl;

        std::cout << robot << std::endl;

        bob.signForm(contract);
        alice.signForm(contract);
        bob.executeForm(contract);
        std::cout << std::endl;
        bob.signForm(robot);
        bob.executeForm(robot);

        std::cout << contract << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}