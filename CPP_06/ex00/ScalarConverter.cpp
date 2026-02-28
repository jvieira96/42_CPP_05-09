#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter created" << std::endl; 
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	(void)src;
	std::cout << "Assigment operator called" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destroyed" << std::endl;
}

static bool isChar(const std::string &input) {
	if(input.length() == 1 && !std::isdigit(input[0])) {
		return true;
	}
	return false;
}

static bool isInt(const std::string &input) {
	size_t i = 0;
	if(input[i] == '-' || input[i] == '+') 
		i++;
	if(!input[i])
		return false;
	for(; i < input.length(); i++) {
		if(!std::isdigit(input[i]))
			return false;
	}
	return true;
}

static void charConvert(const std::string &input) {
	char c = static_cast<char>(input[0]);
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convert(const std::string &input) {
	if(isChar(input)) {
		charConvert(input);
	}
	else if(isInt(input)) {

	}
/* 	elif(isFloat) {

	}
	elif(isDouble){

	} */
}