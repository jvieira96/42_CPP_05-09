#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class Form;

class Bureaucrat {

private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &src);
	~Bureaucrat();

	const std::string 	getName() const;
	int					getGrade() const;
	void 				increment();
	void				decrement();
	class GradeTooHighException : public std::exception {
		public:
			 virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			 virtual const char* what() const throw();
	};

	void signForm(Form &form) const;

};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bur);

#endif