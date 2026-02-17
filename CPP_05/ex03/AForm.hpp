#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class AForm {

private:
	const std::string	_name;
	bool				_is_signed;
	const int			_sign_grade;
	const int			_exec_grade;

public:
	AForm(const std::string name, const int sign, const int exec);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &src);
	~AForm();

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	class GradeTooHighException : public std::exception {
		public:
			 virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			 virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception {
		public:
			 virtual const char* what() const throw();
	};

	void 			beSigned(const Bureaucrat &bur);
	void			execute(const Bureaucrat &executor) const;
	virtual void 	execution() const = 0;
};

std::ostream& operator<<(std::ostream &output, const AForm &form);

#endif