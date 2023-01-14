#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", "notarget", 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon", target, 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& f) : AForm(f.getName(), f.getTarget(), f.getGradeForSign(), f.getGradeForExecute()) {

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

	std::cout << '\n' << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.\n\n";
}
