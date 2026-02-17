#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>
#include <cstdlib>

int main() {

	std::srand(std::time(0));
	Bureaucrat steve("Steve", 5);
	Bureaucrat roger("Roger", 149);
	PresidentialPardonForm PForm("PForm");
	RobotomyRequestForm RForm("RForm");
	ShrubberyCreationForm SForm("SForm");

	std::cout << "\n----------Bureaucrats Info----------" << std::endl;
	std::cout << steve << std::endl;
	std::cout << roger << std::endl;
	
	std::cout << "\n----------Testing PresedentialForm----------" << std::endl;
	roger.signForm(PForm);
	steve.executeForm(PForm);
	steve.signForm(PForm);
	roger.executeForm(PForm);
	steve.signForm(PForm);
	steve.executeForm(PForm);

	std::cout << "\n----------Testing RobotomyRequestForm----------" << std::endl;
	roger.signForm(RForm);
	steve.executeForm(RForm);
	steve.signForm(RForm);
	roger.executeForm(RForm);
	steve.signForm(RForm);
	steve.executeForm(RForm);
	
	std::cout << "\n----------Testing ShrubberyCreationForm----------" << std::endl;
	roger.signForm(SForm);
	steve.executeForm(SForm);
	steve.signForm(SForm);
	roger.executeForm(SForm);
	steve.signForm(SForm);
	steve.executeForm(SForm);
	
	std::cout << "\n" << std::endl;

	return(0);

}