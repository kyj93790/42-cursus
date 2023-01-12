#ifndef SIGNEXCEPTION_HPP
# define SIGNEXCEPTION_HPP

#include <iostream>
#include <string>
#include <exception>

class SignException : public std::exception
{
	private:
		const char* _msg;
	public:
		SignException(const char* msg);
		const char* what() const throw();
};

#endif