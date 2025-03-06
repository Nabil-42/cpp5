#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <climits>

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 1);
        
        ShrubberyCreation contract("Schrubery Contract");

        std::cout << contract << std::endl;

        bob.signForm(contract);
        alice.signForm(contract);

        std::cout << contract << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}