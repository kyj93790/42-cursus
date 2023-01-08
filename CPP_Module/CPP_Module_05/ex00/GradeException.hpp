#ifndef GRADEEXCEPTION_HPP
# define GRADEEXCEPTION_HPP

#include <iostream>
#include <string>
#include <exception>

class GradeException : public std::exception
{
	private:
		const char* _msg;
	public:
		GradeException(const char* msg);
		const char* what() const throw();
};

#endif