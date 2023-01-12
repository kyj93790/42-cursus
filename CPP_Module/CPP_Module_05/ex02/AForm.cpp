#include "AForm.hpp"

AForm::AForm() : _name("noname"), _isSigned(false), _gradeForSign(150), _gradeForExecute(150)
{
}

AForm::AForm(std::string name, int gradeForSign, int gradeForExecute) \
	: _name(name), _isSigned(false), _gradeForSign(gradeForSign), _gradeForExecute(gradeForExecute)
{
	if (_gradeForSign < 1) throw GradeTooHighException();
	else if (_gradeForSign > 150) throw GradeTooLowException();

	if (_gradeForExecute < 1) throw GradeTooHighException();
	else if (_gradeForExecute > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm& f) : _name(f._name), _isSigned(f._isSigned), _gradeForSign(f._gradeForSign), _gradeForExecute(f._gradeForExecute)
{
}

AForm::~AForm()
{
}

const AForm& AForm::operator=(const AForm& f)
{
	return (f);
}

GradeException AForm::GradeTooHighException() const
{
	return GradeException("Grade is too high");
}

GradeException AForm::GradeTooLowException() const
{
	return GradeException("Grade is too low");
}

const std::string AForm::getName() const
{
	return (_name);
}

bool AForm::isSigned() const
{
	return (_isSigned);
}

int AForm::getGradeForSign() const
{
	return (_gradeForSign);
}

int AForm::getGradeForExecute() const
{
	return (_gradeForExecute);
}

void AForm::beSigned(Bureaucrat b)
{
	int grade = b.getGrade();

	if (grade <= _gradeForSign) {
		_isSigned = true;
	} else {
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "----------AForm info----------\n";
	os << "Name              : " << f.getName() << '\n';
	os << "Signed            : ";
	if (f.isSigned())
		os << "true" << '\n';
	else
		os << "false" << '\n';
	os << "GradeForSign      : " << f.getGradeForSign() << '\n';
	os << "GradeForExecution : " << f.getGradeForExecute() << '\n';
	os << "-----------------------------\n";
	return (os);
}

SignException AForm::IsNotSignedException() const
{
	return SignException("Form is not signed");
}

FileException AForm::OpenFailException() const
{
	return FileException("File open failed");
}