#include "PmergeMe.hpp"

int main (int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: Ivalid input!";
        return 1;
    }
    PmergeMe nbrs(ac, av);

}