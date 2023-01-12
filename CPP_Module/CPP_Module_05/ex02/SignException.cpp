#include "SignException.hpp"

SignException::SignException(const char* msg) : _msg(msg)
{

}

const char* SignException::what() const throw()
{
	return _msg;
}