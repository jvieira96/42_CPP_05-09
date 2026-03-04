#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if(argc == 1)
		std::cerr << "ERROR: no param" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}