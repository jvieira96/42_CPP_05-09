#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"





class Intern {

public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &src);
	~Intern();

	void makeForm(std::string formName, std::string target);
};

#endif 