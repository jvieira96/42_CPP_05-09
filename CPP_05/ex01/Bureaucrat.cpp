#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(0) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		_grade = grade;
		
	std::cout << GRN << "Bureaucrat named " << _name << " created" << RES << std::endl;
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
	std::cout << RED << "Bureaucrat named " << _name << " destroyed" << RES << std::endl;
}

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::increment() {
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
	std::cout << BCYA << "Bureaucrat " << _name << " grade incremented, new grade: " << _grade << RES << std::endl;
}

void Bureaucrat::decrement() {
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
	std::cout << BCYA << "Bureaucrat " << _name << " grade decremented, new grade: " << _grade << RES << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "ERROR: Grade is too high! The highest grade is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "ERROR: Grade is too low! The lowest grade is 150.";
}

std::ostream& operator<<(std::ostream &output, const Bureaucrat &bur) {
	output << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return output;
}

void Bureaucrat::signForm(Form &form) const {
	if (form.getIsSigned()) {
		std::cout << BCYA << "Form already signed." << RES << std::endl;
		return;
	}
	try {
		form.beSigned(*this);
		std::cout 	<< BCYA << getName()
					<< " signed " << form.getName() << RES << std::endl;
	}
	catch(std::exception &e) {
		std::cerr 	<< RED << getName() << " couldn't sign " 
					<< form.getName() << " because " << e.what() << RES << std::endl;
	}

}