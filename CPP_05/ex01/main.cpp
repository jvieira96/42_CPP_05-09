#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	
	std::cout << "-----Sign with low grade----" << std::endl;
	try
	{
		Bureaucrat steve("Steve", 149);
		std::cout << YEL << steve << RES << std::endl;
		Form form("form1", 100, 120);
		std::cout << YEL << form << RES << std::endl;
		steve.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n-----Sign with ok grade----" << std::endl;
	try
	{
		Bureaucrat carlos("Carlos", 99);
		std::cout << YEL << carlos << RES << std::endl;
		Form form("form2", 110, 120);
		std::cout << YEL << form << RES << std::endl;
		carlos.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return(0);

}