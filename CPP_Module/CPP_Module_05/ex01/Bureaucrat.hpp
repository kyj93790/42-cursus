#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "GradeException.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
		Bureaucrat();
	public:
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat& b);
		~Bureaucrat();
		const Bureaucrat& operator=(const Bureaucrat& b);
		const std::string getName() const;
		int getGrade() const;
		void upGrade();
		void downGrade();
		GradeException GradeTooHighException() const;
		GradeException GradeTooLowException() const;
		void signForm(Form *f);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif