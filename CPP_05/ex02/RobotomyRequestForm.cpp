#include "RobotomyRequestForm.hpp"
#include <cstdlib>

 RobotomyRequestForm::RobotomyRequestForm(std::string target)
 	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
		std::cout 	<< GRN << "RobotomyRequestForm created" << RES << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
	: AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade()) {
		_target = copy._target;
		std::cout	<< YEL << "RobotomyRequestForm copy constructor called" 
					<< RES << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm &src) {
	if (this != &src)
		_target = src._target;
	std::cout << YEL << "RobotomyRequestForm operator called" << RES << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout 	<< RED << "RobotomyRequestForm destroyed" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::execution() const {
	std::cout << BCYA << "grrr...grrr...grrr..." << RES << std::endl;
	if(std::rand() % 2) 
		std::cout << GRN << _target << " has been robotomized" << RES << std::endl;
	else
		std::cout << RED << _target << " failed robotomization" << RES << std::endl;
}