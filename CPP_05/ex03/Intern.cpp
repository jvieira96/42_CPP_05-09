#include "Intern.hpp"

Intern::Intern() {
	std::cout << GRN << "Intern created" << RES << std::endl;
}

Intern::Intern(const Intern &copy) {
	*this = copy;
	std::cout << YEL << "Intern copy constructor called" << RES << std::endl;
}

Intern& Intern::operator=(const Intern &src) {
	(void)src;
	std::cout << YEL << "Assignment operator called" << RES << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << RED << "Intern destroyed" << RES << std::endl;
}

void Intern::makeForm(std::string formName, std::string target) {
	std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int index = 42;

	for (int i = 0; i < 3; i++) {
		if (forms[i] == formName)
		
	}
}