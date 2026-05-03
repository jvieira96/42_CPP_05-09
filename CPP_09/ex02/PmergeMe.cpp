#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av) {

    for (int i = 1; i < ac; i++) {
        std::istringstream s(av[i]);
        long n;
        if(!(s >> n) || !s.eof() || n <= 0 || n > INT_MAX) {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
    _vector.push_back(static_cast<int>(n));
    _deque.push_back(static_cast<int>(n));
    }

}