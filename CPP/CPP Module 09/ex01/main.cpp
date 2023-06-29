#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Error: only 1 argument needed" << std::endl;
        return 1;
    }

    RPN rpn;

    try {
        rpn.calculate(argv[1]);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}