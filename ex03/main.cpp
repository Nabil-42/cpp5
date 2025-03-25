#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <climits>
#include "Intern.hpp"

int main() {
    try {
        Intern intern;
        AForm* ptr;

        ptr = intern.makeForm("ShrubberyCreationForm", "lemon");
        if (ptr == NULL)
            return 1;

        Bureaucrat alice("alice", 1);
        alice.signForm(*ptr);
        alice.executeForm(*ptr);

        delete ptr;
    }
     catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}