#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const PresidentialPardonForm& operator=(const PresidentialPardonForm& f);
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm& f);
		~PresidentialPardonForm();
		void execute(Bureaucrat const &executor) const;
};

#endif