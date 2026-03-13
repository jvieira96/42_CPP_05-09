#include "iter.hpp"
#include <iostream>

void printInt(int &nbr) {
    std::cout << nbr << std::endl;
}

template <typename T>
void printSomething(T const &something) {
    std::cout << something << std::endl;
}

int main() {

    int intArray[] = {42, 24, 12, 6, 3};
    std::string strArray[] = {"forthy2", "damn", "check"};
    int const constArray [] = {1, 2, 3};

    std::cout << "Int array: " << std::endl;
    ::iter(intArray, 5, printInt);

    std::cout << "\nString array: " << std::endl;
    ::iter(strArray, 3, printSomething<std::string>);

    std::cout << "\nConst int array: " << std::endl;
    ::iter(constArray, 3, printSomething<int>);

}