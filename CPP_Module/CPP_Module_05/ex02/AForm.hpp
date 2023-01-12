#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
# include <fstream>
#include "GradeException.hpp"
#include "Bureaucrat.hpp"
#include "SignException.hpp"
#include "FileException.hpp"

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeForSign;
		const int _gradeForExecute;
		const AForm& operator=(const AForm& f);
	public:
		AForm();
		AForm(std::string name, int gradeForSign, int gradeForExecute);
		AForm(const AForm& f);
		virtual ~AForm();
		GradeException GradeTooHighException() const;
		GradeException GradeTooLowException() const;
		const std::string getName() const;
		bool isSigned() const;
		int getGradeForSign() const;
		int getGradeForExecute() const;
		void beSigned(Bureaucrat b);
		virtual void execute(Bureaucrat const &executor) const = 0;
		SignException IsNotSignedException() const;
		FileException OpenFailException() const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif