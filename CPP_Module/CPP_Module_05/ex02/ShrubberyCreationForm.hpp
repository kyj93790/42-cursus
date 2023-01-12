#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& f);
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm& f);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const &executor) const;
};

#endif