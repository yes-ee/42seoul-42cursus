#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    (void)argv;
    
    if (argc != 2) {
        std::cout << "argument error: only 1 argument needed" << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    try {
        btc.getDataFromCSV();
        btc.exchange(argv[1]);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}