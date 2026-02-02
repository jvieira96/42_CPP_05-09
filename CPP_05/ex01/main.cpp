#include "Bureaucrat.hpp"

int main() {

	Bureaucrat steve("Steve", 149);

	std::cout << YEL << steve << RES << std::endl;

	try {
		for (int i = 0; i < 2 ; i++) {
			std::cout 	<< "\nDecrementing steve grade...\n";	
			steve.decrement();
		}
	}		
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}

	Bureaucrat carlos("Carlos", 2);

	std::cout << YEL << carlos << RES << std::endl;

	try { 
		for (int i = 0; i < 2 ; i++) {
			std::cout 	<< "\nIncrementing steve grade...\n";	
			carlos.increment();
		}
	}		
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}



	
	return(0);

}