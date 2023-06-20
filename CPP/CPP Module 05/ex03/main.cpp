#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    try {
        Intern i;
        AForm *p;
        AForm* r;
        AForm* s;
        AForm* w;

        p = i.makeForm("PresidentialPardonForm", "home");
        r = i.makeForm("RobotomyRequestForm", "home");
        s = i.makeForm("ShrubberyCreationForm", "home");
        w = i.makeForm("wrongreq", "abc");

        std::cout << std::endl;

        Bureaucrat a("a", 1);
        Bureaucrat b("b", 140);

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        std::cout << std::endl;

        std::cout << *p << std::endl;
        std::cout << *r << std::endl;
        std::cout << *s << std::endl;

        std::cout << std::endl;

        //execute fail - not signed
        a.executeForm(*p);

        std::cout << std::endl;

        a.signForm(*p);
        std::cout << *p << std::endl;
        a.executeForm(*p);

        std::cout << std::endl;

        //execute fail - grade low
        b.executeForm(*p);

        std::cout << std::endl;

        a.signForm(*r);
        a.signForm(*s);

        std::cout << std::endl;

        a.executeForm(*r);
        a.executeForm(*s);
        b.executeForm(*s);

        delete p;
        delete r;
        delete s;
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}