#ifndef FORMEXCEPTION_HPP
# define FORMEXCEPTION_HPP

#include <iostream>
#include <string>
#include <exception>

class FormException : public std::exception
{
	private:
		const char* _msg;
	public:
		FormException(const char* msg);
		const char* what() const throw();
};

#endif