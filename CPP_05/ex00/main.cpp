#include "Bureaucrat.hpp"

int main() {

	std::cout << "-----Create a bureaucrat with invalid grade-----" << std::endl;
	try {
		Bureaucrat steve("Steve", 151);
		for (int i = 0; i < 2 ; i++) {
			std::cout 	<< "\nDecrementing " << steve.getName() << " grade...\n";	
			steve.decrement();
			std::cout << YEL << steve << RES << std::endl;
		}
	}		
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}

	std::cout << "-----Create a bureaucrat with Valid grade-----" << std::endl;
	try {
		Bureaucrat carlos("Carlos", 2);
		for (int i = 0; i < 2 ; i++) {
			std::cout 	<< "\nIncrementing " << carlos.getName() << " grade...\n";	
			carlos.increment();
			std::cout << YEL << carlos << RES << std::endl;
		}
	}		
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}



	
	return(0);

}