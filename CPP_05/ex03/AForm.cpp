#include "AForm.hpp"

AForm::AForm(const std::string name, const int sign, const int exec)
	: _name(name), _is_signed(false), _sign_grade(sign), _exec_grade(exec) {
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
	else if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	std::cout << GRN << "Form named " << _name << " created" << RES << std::endl;
}

AForm::AForm(const AForm &copy) 
	: _name(copy.getName()), _is_signed(copy.getIsSigned()), 
	_sign_grade(copy.getSignGrade()), _exec_grade(copy.getExecGrade()) {
	std::cout << YEL << "Copy construct called" << RES << std::endl;
}

AForm& AForm::operator=(const AForm &src) {
	if (this != &src) {
		_is_signed = src._is_signed;
	}
	std::cout << YEL << "Assignment operator called" << RES << std::endl;
	return *this;
}

AForm::~AForm() {
	std::cout << RED << "Form named " << _name << " destroyed" << RES << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "ERROR: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "ERROR: Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "ERROR: Form not signed!";
}

bool AForm::getIsSigned() const {
	return _is_signed;
}

int AForm::getSignGrade() const {
	return _sign_grade;
}

int AForm::getExecGrade() const {
	return _exec_grade;
}

std::string AForm::getName() const {
	return _name;
}

std::ostream& operator<<(std::ostream &output, const AForm &form) {
	output 	<< YEL << "Name: " << form.getName() << std::endl
			<< "signed: " << (form.getIsSigned() ? "True" : "False") << std::endl
			<< "sign grade: " << form.getSignGrade() << std::endl
			<< "exec grade: " << form.getExecGrade() << RES << std::endl;
	return output;
}

void AForm::beSigned(const Bureaucrat &bur) {
	if (getSignGrade() >= bur.getGrade()) 
		_is_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!_is_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _exec_grade)
		throw GradeTooLowException();
	execution();
};
