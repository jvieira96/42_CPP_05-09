#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {

private:
	const std::string	_name;
	bool				_is_signed;
	const int			_sign_grade;
	const int			_exec_grade;

public:
	Form(const std::string name, const int sign, const int exec);
	Form(const Form &copy);
	Form &operator=(const Form &src);
	~Form();

	class GradeTooHighException : public std::exception {
		public:
			 virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			 virtual const char* what() const throw();
	};
};


#endif