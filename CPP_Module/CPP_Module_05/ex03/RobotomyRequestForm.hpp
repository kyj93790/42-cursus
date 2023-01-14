#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		const RobotomyRequestForm& operator=(const RobotomyRequestForm& f);
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm& f);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;
		static AForm* createForm(std::string target);
};

#endif