#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("noname", 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& f) : AForm(f.getName(), f.getGradeForSign(), f.getGradeForExecute()) {

}

PresidentialPardonForm::~PresidentialPardonForm() {

}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& f) {
	return (f);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (this->isSigned() == false) {
		throw IsNotSignedException();
	} else if (this->getGradeForExecute() < executor.getGrade()) {
		throw GradeTooLowException();
	}

	std::cout << '\n' << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n\n";
}
