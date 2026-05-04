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

PmergeMe::PmergeMe(const PmergeMe &copy) : _vector(copy._vector), _deque(copy._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        _vector = src._vector;
        _deque = src._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector() {
    std::vector<std::pair<int,int>> pairs;

    for (size_t i = 0; i + 1 < _vector.size(); i += 2) {
        int n1 = _vector[i];
        int n2 = _vector[i + 1];
        if (n1 > n2)
            std::swap(n1, n2);
        pairs.push_back(std::make_pair(n1, n2));
    }

    int oddNbr = -1;
    if (_vector.size() % 2 != 0)
        oddNbr = _vector.back();
}

void PmergeMe::mergeInsertVec(std::vector<int> &chain) {
    if (chain.size() <= 1)
        return;

    std::vector<std::pair<int,int>> pairs;
    for (size_t i = 0; i + 1 < _vector.size(); i += 2) {
        int n1 = _vector[i];
        int n2 = _vector[i + 1];
        if (n1 > n2)
            std::swap(n1, n2);
        pairs.push_back(std::make_pair(n1, n2));
    }

    int oddNbr = -1;
    if (_vector.size() % 2 != 0)
        oddNbr = _vector.back();

    std::vector<int> larges;
    for (size_t i = 0; i < pairs.size(); i++)
        larges.push_back(pairs[i].second);

    mergeInsertVec(larges);
}