#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", "noname", 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", target, 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& f) : AForm(f.getName(), f.getTarget(), f.getGradeForSign(), f.getGradeForExecute()) {
	
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& f) {
	return (f);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->isSigned() == false) {
		throw IsNotSignedException();
	} else if (this->getGradeForExecute() < executor.getGrade()) {
		throw GradeTooLowException();
	}

	std::ofstream outfile(this->getTarget() + "_shrubbery");
	if (!outfile) {
		throw OpenFailException();
	}

	outfile << "¨¨¨¨¨¨¨¨¨ **\n";
	outfile << "¨¨¨¨¨¨¨¨¨*o*\n";
	outfile << "¨¨¨¨¨¨¨¨*♥*o*\n";
	outfile << "¨¨¨¨¨¨¨***o***\n";
	outfile << "¨¨¨¨¨¨**o**♥*o*\n";
	outfile << "¨¨¨¨¨**♥**o**o**\n";
	outfile << "¨¨¨¨**o**♥***♥*o*\n";
	outfile << "¨¨¨*****♥*o**o****\n";
	outfile << "¨¨**♥**o*****o**♥**\n";
	outfile << "¨******o*****♥**o***\n";
	outfile << "****o***♥**o***o***♥ *\n";
	outfile << "¨¨¨¨¨____!_!____\n";
	outfile << "¨¨¨¨¨_________/¨¨\n";

	outfile.close();
}