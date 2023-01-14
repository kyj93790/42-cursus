#include "FormException.hpp"

FormException::FormException(const char* msg) : _msg(msg)
{

}

const char* FormException::what() const throw()
{
	return _msg;
}