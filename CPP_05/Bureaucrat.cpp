#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {

}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << YEL << "Copy construct called" << RES << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src) {
		this->_grade = src._grade;
	}
	std::cout << YEL << "Assignment operator called" << RES << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED << "Bureaucrat named" << _name << "destroyed" << RES << std::endl;
}

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "ERROR: Grade is too high! The highest grade is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "ERROR: Grade is too low! The lowest grade is 150.";
}