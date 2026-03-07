#include "Data.hpp"
#include "Serializer.hpp"

int main(void) {

	Data data;

	data.name = "Joao";
	data.age = 29;

	std::cout << "Pointer Adress: " << &data << std::endl;
	std::cout << "Data: " << data.name << ", " << data.age << std::endl;

	uintptr_t rawValue = Serializer::serialize(&data);
	std::cout << "\nSerialized value (as int): "<< rawValue << std::endl;

	Data* result = Serializer::deserialize(rawValue);
	std::cout << "\nDeserialized pointer adress: "<< result << std::endl;
	std::cout << "Deserialized pointer data: " << result->name << ", " << result->age << std::endl;

	return 0;
}