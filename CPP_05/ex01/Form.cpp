#include "Form.hpp"

Form::Form(const std::string name, const int sign, const int exec)
	: _name(name), _is_signed(false), _sign_grade(sign), _exec_grade(exec) {
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
	else if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	std::cout << GRN << "Form named " << _name << " created\n" << RES << std::endl;
}

Form::Form(const Form &copy) 
	: _name(copy.getName()), _is_signed(copy.getIsSigned()), 
	_sign_grade(copy.getSignGrade()), _exec_grade(copy.getExecGrade()) {
	std::cout << YEL << "Copy construct called" << RES << std::endl;
}

Form& Form::operator=(const Form &src) {
	if (this != &src) {
		_is_signed = src._is_signed;
	}
	std::cout << YEL << "Assignment operator called" << RES << std::endl;
	return *this;
}

Form::~Form() {
	std::cout << RED << "Form named " << _name << " destroyed" << RES << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "ERROR: Grade is too high!\n";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "ERROR: Grade is too low!\n";
}

bool Form::getIsSigned() const {
	return _is_signed;
}

int Form::getSignGrade() const {
	return _sign_grade;
}

int Form::getExecGrade() const {
	return _exec_grade;
}

std::string Form::getName() const {
	return _name;
}

std::ostream& operator<<(std::ostream &output, const Form &form) {
	output 	<< YEL << "Name: " << form.getName() << std::endl
			<< "signed: " << (form.getIsSigned() ? "True" : "False") << std::endl
			<< "sign grade: " << form.getSignGrade() << std::endl
			<< "exec grade: " << form.getExecGrade() << RES << std::endl;
	return output;
}

void Form::beSigned(const Bureaucrat &bur) {
	if (getSignGrade() >= bur.getGrade()) 
		_is_signed = true;
	else
		throw GradeTooLowException();
}