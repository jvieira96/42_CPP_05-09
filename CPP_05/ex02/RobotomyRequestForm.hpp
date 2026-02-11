#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	
	private:
		std::string _target;

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm& operator =(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		std::string getTarget() const;
		void 		execution() const;
};



#endif