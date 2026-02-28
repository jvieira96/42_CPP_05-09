#include "ShrubberyCreationForm.hpp"
#include <fstream>

 ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
 	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
		std::cout 	<< GRN << "ShrubberyCreationForm created" << RES << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
	: AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade()) {
		_target = copy._target;
		std::cout	<< YEL << "ShrubberyCreationForm copy constructor called" 
					<< RES << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &src) {
	if (this != &src)
		_target = src._target;
	std::cout << YEL << "ShrubberyCreationForm operator called" << RES << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout 	<< RED << "ShrubberyCreationForm destroyed" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::execution() const {
	std::string name = _target + "_Shrubbery";
	std::ofstream file(name.c_str());
	if (!file) {
		std::cerr << RED << "Error: could not open file " << name << RES << std::endl;
		return;
	}
	file << "         ccee88oo          " << std::endl;
	file << "  C8O8O8Q8PoOb o8oo        " << std::endl;
	file << "  dOB69QO8PdUOpugoO9bD     " << std::endl;
	file << "  CgggbU8OU qOp qOdoUOdcb  " << std::endl;
	file << "      6OuU  /p u gcoUodpP  " << std::endl;
	file << "      ||||||//  /douUP     " << std::endl;
	file << "        ||||||///          " << std::endl;
	file << "          |||/||           " << std::endl;
	file << "          |||||/           " << std::endl;
	file << "          |||||            " << std::endl;
	file << "    .....//||||||....      " << std::endl;

	std::cout << GRN << "Shrubbery Form  \"" << name << "\" created" << RES << std::endl;
}