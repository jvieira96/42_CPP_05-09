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

static bool isFloat(const std::string &input) {
	size_t i = 0;
	int dotCount = 0;
	int digitCount = 0;

	if(input[input.length() - 1] != 'f')
		return false;
	if(input == "-inff" || input == "+inff" || input == "nanf")
		return true;
	if(input[i] == '-' || input[i] == '+')
	i++;

	if(!input[i])
		return false;
	for(; i < input.length() - 1; i++) {
		if (input[i] == '.')
			dotCount++;
		else if(std::isdigit(input[i]))
			digitCount++;
		else
			return false;
	}
	if(dotCount == 1 && digitCount > 0)
		return true;

	return false;

}

static bool isDouble(const std::string &input) {
	size_t i = 0;
	int dotCount = 0;
	int digitCount = 0;

	if(input == "-inf" || input == "+inf" || input == "nan")
		return true;
	if(input[i] == '-' || input[i] == '+')
	i++;

	if(!input[i])
		return false;
	for(; i < input.length(); i++) {
		if (input[i] == '.')
			dotCount++;
		else if(std::isdigit(input[i]))
			digitCount++;
		else
			return false;
	}
	if(dotCount == 1 && digitCount > 0)
		return true;

	return false;

}

static void charConvert(const std::string &input) {
	char c = static_cast<char>(input[0]);
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void intConvert(const std::string &input) {
	long nbr = std::strtol(input.c_str(), NULL, 10);
	int i;

	if (nbr > INT_MAX || nbr < INT_MIN) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1)
				  << static_cast<float>(nbr) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1)
				  << static_cast<double>(nbr) << std::endl;
	}
	else {
		i = static_cast<int>(nbr);
		if (i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(i))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1)
				  << static_cast<float>(nbr) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1)
				  << static_cast<double>(nbr) << std::endl;
	}
}

void ScalarConverter::convert(const std::string &input) {
	if (input.empty()) {
		std::cout << "Invalid use" << std::endl;
		return;
	}
	if(isChar(input))
		charConvert(input);
	else if(isInt(input))
		intConvert(input); // implement
	else if(isFloat)
		floatConvert(input); // implement
	else if(isDouble)
		doubleConvert(input); // implement
}