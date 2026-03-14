#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {

	std::cout << "----- Testing with vector -----" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 5; i++)
		vec.push_back(i + 1);
	try {
		easyfind(vec, 1);
		easyfind(vec, 3);
		easyfind(vec, 10);
	}
	catch (const std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	
	std::cout << "----- Testing with list -----" << std::endl;
	std::list<int> lis;
	for (int i = 0; i < 5; i++)
		lis.push_back(i + 1);
	try {
		easyfind(lis, 1);
		easyfind(lis, 3);
		easyfind(lis, 10);
	}
	catch (const std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	return 0;
}