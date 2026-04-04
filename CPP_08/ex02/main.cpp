#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::cout << "--- Mandatory Subject Tests ---" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "Top:  " << mstack.top() << std::endl; // Should be 17

        mstack.pop();

        std::cout << "Size: " << mstack.size() << std::endl; // Should be 1

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "\n--- Comparison with std::list ---" << std::endl;
    {
        std::list<int> lstack;

        lstack.push_back(5);
        lstack.push_back(17);

        std::cout << "Back: " << lstack.back() << std::endl;

        lstack.pop_back();

        std::cout << "Size: " << lstack.size() << std::endl;

        lstack.push_back(3);
        lstack.push_back(5);
        lstack.push_back(737);
        lstack.push_back(0);

        std::list<int>::iterator it = lstack.begin();
        std::list<int>::iterator ite = lstack.end();

        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    std::cout << "\n--- Testing Reverse Iterators & Const ---" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);

        MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
        MutantStack<int>::const_reverse_iterator crite = mstack.rend();

        std::cout << "Reverse display:" << std::endl;
        while (crit != crite)
        {
            std::cout << *crit << " ";
            ++crit;
        }
        std::cout << std::endl;
    }

    return 0;
}
