#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "GradeException.hpp"
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeForSign;
		const int _gradeForExecute;
		const Form& operator=(const Form& f);
	public:
		Form();
		Form(std::string name, int gradeForSign, int gradeForExecute);
		Form(const Form& f);
		~Form();
		GradeException GradeTooHighException() const;
		GradeException GradeTooLowException() const;
		const std::string getName() const;
		bool getSigned() const;
		int getGradeForSign() const;
		int getGradeForExecute() const;
		void beSigned(Bureaucrat b);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif