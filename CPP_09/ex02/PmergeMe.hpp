#include <vector>
#include <deque>
#include <iostream>
#include <climits>
#include <cstdlib>

class PmergeMe {

    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

    public:
        PmergeMe();
        PmergeMe(int ac, char **av);
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        void sortVector():
        void mergeInsertVec(std::vector<int> &chain);

}