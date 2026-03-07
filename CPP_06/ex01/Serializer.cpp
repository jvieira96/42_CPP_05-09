#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer() {
	std::cout << "Serializer created" << std::endl;
}

Serializer::Serializer(const Serializer &copy) {
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src) {
	(void)src;
	std::cout << "Assigment operator called" << std::endl;
	return *this;
}

Serializer::~Serializer() {
	std::cout << "Serializer destroyed" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}