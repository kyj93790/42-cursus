#include "Intern.hpp"

Intern::Intern()
{
	formNames[0] = "shrubbery creation";
	formNames[1] = "robotomy request";
	formNames[2] = "presidential pardon";

	f[0] = &ShrubberyCreationForm::createForm;
	f[1] = &RobotomyRequestForm::createForm;
	f[2] = &PresidentialPardonForm::createForm;
}

Intern::Intern(const Intern &intern)
{
	formNames[0] = intern.formNames[0];
	formNames[1] = intern.formNames[1];
	formNames[2] = intern.formNames[2];

	f[0] = intern.f[0];
	f[1] = intern.f[1];
	f[2] = intern.f[2];
}

Intern::~Intern()
{
}

const Intern& Intern::operator=(const Intern& intern)
{
	(void)intern;
	return (*this);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::cout << "Intern creates " << name << '\n';
	for (int i=0; i<3; i++) {
		if (name == formNames[i]) return f[i](target);
	}
	throw IsNotKindOfForm();
}

FormException Intern::IsNotKindOfForm() const
{
	return FormException("Not a kind of Form");
}