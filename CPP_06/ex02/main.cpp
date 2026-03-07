#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Identify.hpp"

int main(void) {
	std::srand(std::time(NULL));

	std::cout << "----- TEST 1 -----"<< std::endl;
	Base* ptr1 = generate();
	identify(ptr1);
	identify(*ptr1);
	delete ptr1;

	std::cout << "----- TEST 2 -----"<< std::endl;
	Base* ptr2 = generate();
	identify(ptr2);
	identify(*ptr2);
	delete ptr2;

	return 0;

}