#include "PresidentialPardonForm.hpp"

 PresidentialPardonForm::PresidentialPardonForm(std::string target)
 	: AForm(target, 25, 5), _target(target) {
		std::cout 	<< GRN << "PresidentialPardonForm target: "
					<< target << " created" << RES << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) 
	: AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade()) {
		_target = copy._target;
		std::cout	<< YEL << "PresidentialPardonForm copy constructor called" 
					<< RES << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &src) {
	if (this != &src)
		_target = src._target;
	std::cout << YEL << "PresidentialPardonForm operator called" << RES << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout 	<< RED << "PresidentialPardonForm target: " 
				<< _target << " destroyed" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::execution() const {
	std::cout << BCYA << _target << " has been pardoned by Zaphod Beeblebrox." << RES << std::endl;
}