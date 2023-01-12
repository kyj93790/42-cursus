#include "FileException.hpp"

FileException::FileException(const char* msg) : _msg(msg)
{

}

const char* FileException::what() const throw()
{
	return _msg;
}