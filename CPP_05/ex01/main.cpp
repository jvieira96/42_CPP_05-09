#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	Bureaucrat steve("Steve", 149);

	std::cout << YEL << steve << RES << "\n" << std::endl;

	Form form("form1", 100, 120);

	std::cout << YEL << form << RES << std::endl;

	steve.signForm(form);
	
	Bureaucrat carlos("Carlos", 99);

	carlos.signForm(form);

	std::cout << YEL << form << RES << std::endl;

	carlos.signForm(form);

	return(0);

}