#include "Data.hpp"

Data::Data() {
	std::cout << "Data created" << std::endl;
}

Data::Data(const Data &copy) {
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

Data &Data::operator=(const Data &src) {
	if (this != &src) {
		this->age = src.age;
		this->name = src.name;
	}
	std::cout << "Assigment operator called" << std::endl;
	return *this;
}

Data::~Data() {
	std::cout << "Data destroyed" << std::endl;
}
