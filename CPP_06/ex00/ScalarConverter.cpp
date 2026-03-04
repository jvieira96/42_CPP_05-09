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


static int type(const std::string &input) {
	if (input == "-inff" || input == "+inff" || input == "nanf"
		|| input == "-inf" || input == "+inf" || input == "nan")
		return (PSEUDO);
	if (input.length() == 1 && !std::isdigit(input[0]))
		return (CHAR);
	size_t i = 0;
	int dots = 0;
	int digits = 0;
	bool f = false;

	if(input[i] == '-' || input[i] == '+')
		i++;
	if(!input[i])
		return (UNKNOWN);
	for(; i < input.length(); i++) {
		if(std::isdigit(input[i]))
			digits++;
		else if (input[i] == '.')
			dots++;
		else if (input[i] == 'f' && i == input.length() - 1)
			f = true;
		else
			return (UNKNOWN);
	}
	if (digits == 0 || dots > 1)
		return (UNKNOWN);
	if (dots == 0 && !f)
		return(INT);
	if (dots == 1 && f)
		return (FLOAT);
	if (dots == 1 && !f)
		return (DOUBLE);
	return (UNKNOWN);
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
	}
		std::cout << "float: " << std::setprecision(1) << static_cast<float>(nbr) << "f" << std::endl;
		std::cout << "double: " << std::setprecision(1) << static_cast<double>(nbr) << std::endl;
}

static void floatConvert(const std::string &input) {
	double val = std::strtod(input.c_str(), NULL);
	float f = static_cast<float>(val);

	if (val < 0 || val > 127)
		std::cout << "char: impossible" << std::endl;
	else {
		int c = static_cast<int>(f);
		if (!std::isprint(c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
		}
	if (val > INT_MAX || val < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (f == static_cast<long>(f)) {
		std::cout << "float: " << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::setprecision(1) << static_cast<double>(f) << std::endl;
	}
	else {
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

static void doubleConvert(const std::string &input) {
	double val = std::strtod(input.c_str(), NULL);

	if (val < 0 || val > 127)
		std::cout << "char: impossible" << std::endl;
	else {
		int c = static_cast<int>(val);
		if (!std::isprint(c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
		}
	if (val > INT_MAX || val < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	if (val == static_cast<long>(val)) {
		std::cout << "float: " << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
		std::cout << "double: " << std::setprecision(1) << static_cast<double>(val) << std::endl;
	}
	else {
		std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << std::endl;
	}
}

static void pseudoConvert(const std::string &input) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input == "nan" || input == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "+inf" || input == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (input == "-inf" || input == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &input) {
	if (input.empty()) {
		std::cout << "ERROR: empty param" << std::endl;
		return;
	}
	int option = type(input);
	switch (option) {
		case CHAR:
			charConvert(input);
			break;
		case INT:
			intConvert(input);
			break;
		case FLOAT:
			floatConvert(input);
			break;
		case DOUBLE:
			doubleConvert(input);
			break;
		case PSEUDO:
			pseudoConvert(input);
			break;
		default: std::cout << "Invalid" << std::endl;
	}

}
