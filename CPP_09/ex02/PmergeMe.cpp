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
    mergeInsertVec(_vector);
}

void PmergeMe::mergeInsertVec(std::vector<int> &chain) {
    if (chain.size() <= 1)
        return;

    std::vector<std::pair<int,int>> pairs;
    for (size_t i = 0; i + 1 < chain.size(); i += 2) {
        int n1 = chain[i];
        int n2 = chain[i + 1];
        if (n1 > n2)
            std::swap(n1, n2);
        pairs.push_back(std::make_pair(n1, n2));
    }

    int oddNbr = -1;
    if (chain.size() % 2 != 0)
        oddNbr = chain.back();

    std::vector<int> larges;
    for (size_t i = 0; i < pairs.size(); i++)
        larges.push_back(pairs[i].second);

    mergeInsertVec(larges);

    std::vector<int> main_chain(larges);
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); i ++)
        pend.push_back(pairs[i].first);

    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1); bound = std::find(mainChain.begin(), mainChain.end(), pairs[k-1].second);
                std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), bound, pend[k-1]);
                mainChain.insert(pos, pend[k-1]);
                inserted[k-1] = true;
    jacobsthal.push_back(1);
    while (jacobsthal.back() < pend.size())
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);

    main_chain.insert(main_chain.begin(), pend[0]);

    size_t jacobIndex = 2;
    while (jacobIndex < jacobsthal.size()) {
        size_t prev = jacobsthal[jacobIndex - 1];
        size_t curr = jacobsthal[jacobIndex];

        size_t end;
        if (curr < pend.size())
            end = curr;
        else
            end = pend.size();

        for (size_t k = end; k > prev; k--) {
            std::vector<int>::iterator big_bro = std::find(main_chain.begin(), main_chain.end(), pairs[k - 1]);
            std::vector<int>::iterator pos = std::lower_bound
        }
    }
}