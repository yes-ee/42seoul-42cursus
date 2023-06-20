#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat a("a", 1);
        std::cout << a << std::endl;
        try {
            a.decreaseGrade();
            a.increaseGrade();
            a.increaseGrade();
        }
        catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b("b", 151);
        std::cout << b << std::endl;
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}