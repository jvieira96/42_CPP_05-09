#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {

	std::srand(std::time(0));
	Intern someRandomIntern;
	Bureaucrat charles("Charles", 1);
	AForm* form1 = NULL;
	AForm* form2 = NULL;

	std::cout << "\n-----Testing with correc form name-----" << std::endl;
	try
	{
		form1 = someRandomIntern.makeForm("robotomy request", "Bender");
		charles.signForm(*form1);
		charles.executeForm(*form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----Testing with wrong form name-----" << std::endl;
	try
	{
		form2 = someRandomIntern.makeForm("wrong request", "Bender");
		charles.signForm(*form2);
		charles.executeForm(*form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	delete form1;
	delete form2;
	return(0);

}