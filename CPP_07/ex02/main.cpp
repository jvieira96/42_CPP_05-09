#include "Array.hpp"
#include <string>
#include <iostream>

int main(){
	std::cout << "----- Basic tests -----" << std::endl;
	Array<int> numbers(5);
	std::cout << "Array size: " << numbers.size() << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "index [" << i << "]: " << numbers[i] << std::endl;

	std::cout << "\n----- Deep copy tests -----" << std::endl;
	Array<int> copy(numbers);
	Array<int> assign = numbers;
	copy[0] = 1;
	assign[0] = 2;
	std::cout << "original[0]: " << numbers[0] << std::endl;
	std::cout << "copy[0]: " << copy[0] << std::endl;
	std::cout << "assign[0]: " << assign[0] << std::endl;

	std::cout << "\n----- Test exception -----" << std::endl;
	try {
		std::cout << "Accessing index 0... " << numbers[0] << std::endl;
		std::cout << "Accessing index -2..." << numbers[-2] << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "\n----- String Array -----" << std::endl;
	Array<std::string>  strings(3);
	strings[0] = "Hello";
	strings[1] = "42";
	strings[2] = "Porto";
	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << strings[i] << std::endl;

	std::cout << "\n----- Const Array -----" << std::endl;
	const Array<int> const_array(2);
	std::cout << "const access[0]: " << const_array[0] << std::endl;

	return 0;
}