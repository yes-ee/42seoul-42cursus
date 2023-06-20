#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat a("a", 1);
        Bureaucrat b("b", 140);
        PresidentialPardonForm p("home");
        RobotomyRequestForm r("home");
        ShrubberyCreationForm s("home");
        std::cout << a << std::endl;

        std::cout << std::endl;

        std::cout << p << std::endl;
        std::cout << r << std::endl;
        std::cout << s << std::endl;

        std::cout << std::endl;

        //execute fail - not signed
        a.executeForm(p);

        std::cout << std::endl;

        a.signForm(p);
        std::cout << p << std::endl;
        a.executeForm(p);

        std::cout << std::endl;

        //execute fail - grade low
        b.executeForm(p);

        std::cout << std::endl;

        a.signForm(r);
        a.signForm(s);

        std::cout << std::endl;

        a.executeForm(r);
        a.executeForm(s);
        b.executeForm(s);
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}