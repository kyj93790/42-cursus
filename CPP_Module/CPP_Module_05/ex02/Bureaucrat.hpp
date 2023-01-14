#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "FormException.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
		Bureaucrat();
	public:
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &b);
		~Bureaucrat();
		const Bureaucrat& operator=(const Bureaucrat &b);
		const std::string getName() const;
		int getGrade() const;
		void upGrade();
		void downGrade();
		FormException GradeTooHighException() const;
		FormException GradeTooLowException() const;
		void signForm(AForm &f);
		void executeForm(AForm const &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif