#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	private:
		std::string formNames[3];
		AForm* (*f[3])(std::string);
	public:
		Intern();
		Intern(const Intern &intern);
		~Intern();
		const Intern& operator=(const Intern& intern);
		AForm* makeForm(std::string name, std::string target);
		FormException IsNotKindOfForm() const;
};

#endif