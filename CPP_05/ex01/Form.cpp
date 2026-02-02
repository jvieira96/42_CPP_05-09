#include "Form.hpp"

Form::Form(const std::string name, const int sign, const int exec)
	: _name(name), _sign_grade(sign), _exec_grade(exec), _is_signed(false) {
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
	else if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	std::cout << GRN << "Form named " << _name << " created\n" << RES << std::endl;
}

Form::Form(const Form &copy) 
	: _name(copy._name), _sign_grade(copy._sign_grade), 
	_exec_grade(copy._exec_grade), _is_signed(copy._is_signed) {
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
	return "ERROR: Grade is too high! The highest grade is 1.\n";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "ERROR: Grade is too low! The lowest grade is 150.\n";