#ifndef FILEEXCEPTION_HPP
# define FILEEXCEPTION_HPP

#include <iostream>
#include <string>
#include <exception>

class FileException : public std::exception
{
	private:
		const char* _msg;
	public:
		FileException(const char* msg);
		const char* what() const throw();
};

#endif