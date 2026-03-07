#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <cctype>

enum e_type{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	UNKNOWN
};

class ScalarConverter {

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &src);
	~ScalarConverter();

public:
	static void convert(const std::string &input);

};

#endif