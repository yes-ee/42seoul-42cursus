#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat a("a", 1);
        Form f("f", 5, 20);
        std::cout << a << std::endl;
        std::cout << f << std::endl;

        try {
            a.decreaseGrade();
        }
        catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        a.signForm(f);
        std::cout << f << std::endl;
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat b("b", 10);
        Form f2("f2", 5, 20);
        std::cout << b << std::endl;
        std::cout << f2 << std::endl;

        b.signForm(f2);
        std::cout << f2 << std::endl;
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}