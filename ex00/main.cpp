#include "Bureaucrat.hpp"
#include <climits>

int main()
{
    try{
        Bureaucrat c("Morade", 1);
        // Bureaucrat a("Nabil", INT_MAX);
        Bureaucrat b("mohamed", 50);

        std::cout << b << std::endl;
        // c.IncrementGrade();
        c.DecrementGrade();
        // a.DecrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception catched : "<< e.what() << std::endl;
    }
    
}