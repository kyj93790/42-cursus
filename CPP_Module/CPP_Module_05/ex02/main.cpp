#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	char temp[10];

	try {
		Bureaucrat a("a", 5);
		Bureaucrat b("b", 150);
		Bureaucrat c("c", 46);
		Bureaucrat d("d", 25);
		Bureaucrat e("e", 145);
		Bureaucrat f("f", 137);

		std::cout << "---------- Test Shrubbery Creation Form ----------\n";
		ShrubberyCreationForm s("s"); /*   145 / 137   */
		b.signForm(s);
		b.executeForm(s);
		std::cout << '\n';
		std::cin.getline(temp, 1);
		e.signForm(s);
		b.executeForm(s);
		std::cout << '\n';
		std::cin.getline(temp, 1);
		e.executeForm(s);
		f.executeForm(s);
		std::cout << '\n';
		std::cin.getline(temp, 1);

		std::cout << "---------- Test Robotomy Request Form ----------\n";
		RobotomyRequestForm r("r"); /*   72 / 45   */
		b.signForm(r);
		d.executeForm(r);
		std::cout << '\n';
		std::cin.getline(temp, 1);
		c.signForm(r);
		c.executeForm(r);
		std::cout << '\n';
		std::cin.getline(temp, 1);
		d.executeForm(r);
		std::cout << '\n';
		std::cin.getline(temp, 1);

		std::cout << "---------- Test Presidential Pardon Form ----------\n";
		PresidentialPardonForm p("p"); /*   25 / 5   */
		b.signForm(p);
		c.signForm(p);
		std::cout << '\n';
		std::cin.getline(temp, 1);
		d.signForm(p);
		d.executeForm(p);
		std::cout << '\n';
		std::cin.getline(temp, 1);
		a.executeForm(p);
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}