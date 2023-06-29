#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Error: wrong argument" << std::endl;
        return 1;
    }

    PmergeMe pm;

    try {
        pm.checkInput(argc, argv);
        pm.print();
        pm.printTime();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}