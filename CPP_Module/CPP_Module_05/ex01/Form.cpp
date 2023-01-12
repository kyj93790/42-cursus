#include "Form.hpp"

Form::Form() : _name("noname"), _isSigned(false), _gradeForSign(150), _gradeForExecute(150)
{
	std::cout << "[Form] Default constructor called\n";
}

Form::Form(std::string name, int gradeForSign, int gradeForExecute) \
	: _name(name), _isSigned(false), _gradeForSign(gradeForSign), _gradeForExecute(gradeForExecute)
{
	std::cout << "[Form] Constructor with attributes called\n";

	if (_gradeForSign < 1) throw GradeTooHighException();
	else if (_gradeForSign > 150) throw GradeTooLowException();

	if (_gradeForExecute < 1) throw GradeTooHighException();
	else if (_gradeForExecute > 150) throw GradeTooLowException();
}

Form::Form(const Form& f) : _name(f._name), _isSigned(f._isSigned), _gradeForSign(f._gradeForSign), _gradeForExecute(f._gradeForExecute)
{
	std::cout << "[Form] Copy constructor with attributes called\n";
}

Form::~Form()
{
	std::cout << "[Form] Destructor called\n";
}

const Form& Form::operator=(const Form& f)
{
	return (f);
}

GradeException Form::GradeTooHighException() const
{
	return GradeException("Grade is too high");
}

GradeException Form::GradeTooLowException() const
{
	return GradeException("Grade is too low");
}

const std::string Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_isSigned);
}

int Form::getGradeForSign() const
{
	return (_gradeForSign);
}

int Form::getGradeForExecute() const
{
	return (_gradeForExecute);
}

void Form::beSigned(Bureaucrat b)
{
	int grade = b.getGrade();

	if (grade <= _gradeForSign) {
		_isSigned = true;
	} else {
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "----------Form info----------\n";
	os << "Name              : " << f.getName() << '\n';
	os << "IsSigned          : ";
	if (f.isSigned())
		os << "true" << '\n';
	else
		os << "false" << '\n';
	os << "GradeForSign      : " << f.getGradeForSign() << '\n';
	os << "GradeForExecution : " << f.getGradeForExecute() << '\n';
	os << "-----------------------------\n";
	return (os);
}