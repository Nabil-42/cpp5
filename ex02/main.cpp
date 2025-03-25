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
        Bureaucrat karim ("Karim", 150);
        
        ShrubberyCreation contract("Contract");
        RobotomyRequest robot ("Human");
        PresidentalPardon panama ("PDD");

        std::cout << contract << std::endl;

        std::cout << robot << std::endl;

        bob.signForm(contract);
        alice.signForm(contract);
        bob.executeForm(contract);
        karim.signForm(panama);
        alice.executeForm(panama);

        std::cout << std::endl << std::endl;
        bob.signForm(robot);
        alice.executeForm(robot);
        std::cout << std::endl << std::endl;
        alice.signForm(panama);
        bob.executeForm(panama);

        std::cout << robot << std::endl;

    }
     catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}