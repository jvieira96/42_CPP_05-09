#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {
    
    if (argc != 2) {
        std::cout << "ERROR: Could not open file" << std::endl;
        return 1;
    }
    
    BitcoinExchange btc;
    if (btc.loadData("data.csv")) {
        btc.processInput(argv[1]);
    }

    return 0;
}