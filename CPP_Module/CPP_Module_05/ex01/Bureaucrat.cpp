#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("anonymous")
{
	std::cout << "[Bureaucrat] Default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name)
{
	std::cout << "[Bureaucrat] Constructor with name and grade called\n";
	if (grade < 1) throw GradeTooHighException();
	else if (grade > 150) throw GradeTooLowException();
	else _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b.getName())
{
	std::cout << "[Bureaucrat] Copy constructor called\n";
	(*this) = b;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] Destructor called\n";
}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	_grade = b._grade;
	return (*this);
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::upGrade()
{
	int grade = _grade - 1;
	
	if (grade < 1) throw GradeTooHighException();
	else if (grade > 150) throw GradeTooLowException();
	else _grade = grade;
}

void Bureaucrat::downGrade()
{
	int grade = _grade + 1;

	if (grade < 1) throw GradeTooHighException();
	else if (grade > 150) throw GradeTooLowException();
	else _grade = grade;
}

GradeException Bureaucrat::GradeTooHighException() const
{
	return GradeException("Grade is too high");
}

GradeException Bureaucrat::GradeTooLowException() const
{
	return GradeException("Grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return (os);
}

void Bureaucrat::signForm(Form &f)
{
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << '\n';
	} catch(std::exception& e) {
		std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << ".\n";
	}
}