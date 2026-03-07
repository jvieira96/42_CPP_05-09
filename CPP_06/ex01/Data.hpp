#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data {
	
public:
	Data();
	Data(const Data &copy);
	Data &operator=(const Data &src);
	~Data();

	std::string name;
	int			age;
};

#endif