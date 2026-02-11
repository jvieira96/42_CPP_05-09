#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	
	private:
		std::string _target;

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm& operator =(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		std::string getTarget() const;
		void 		execution() const;

};



#endif