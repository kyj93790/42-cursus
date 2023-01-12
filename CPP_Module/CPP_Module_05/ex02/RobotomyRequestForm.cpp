#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("noname", 72, 45) {

}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& f) : AForm(f.getName(), f.getGradeForSign(), f.getGradeForExecute()) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& f) {
	return (f);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (this->isSigned() == false) {
		throw IsNotSignedException();
	} else if (this->getGradeForExecute() < executor.getGrade()) {
		throw GradeTooLowException();
	}

	std::cout << "\ndrrrrrrr........drrrrrrr........\n";
	std::ifstream infile("/dev/urandom");
	if (!infile) {
		throw OpenFailException();
	}

	unsigned char c;
	infile >> c;
	if (c & 1) {
		std::cout << this->getName() << " has been robotomized successfully.\n\n";
	} else {
		std::cout << this->getName() << " failed to be robotomized.\n\n";
	}
	infile.close();
}