#include "GradeException.hpp"

GradeException::GradeException(const char* msg) : _msg(msg)
{

}

const char* GradeException::what() const throw()
{
	return _msg;
}