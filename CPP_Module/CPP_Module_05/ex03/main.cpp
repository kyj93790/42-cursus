#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	char temp[10];

	try {
		Bureaucrat a("a", 4);
		Intern someRandomIntern;
		AForm* rrf;

		std::cout << "---------- Test Robotomy Request Form ----------\n";

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf;

		std::cout << '\n';
		std::cin.getline(temp, 1);

		a.signForm(*rrf);
		a.executeForm(*rrf);

		delete rrf;
		std::cout << '\n';
		std::cin.getline(temp, 1);


		std::cout << "---------- Test Shrubbery Creation Form ----------\n";

		rrf = someRandomIntern.makeForm("shrubbery creation", "home");
		std::cout << *rrf;

		std::cout << '\n';
		std::cin.getline(temp, 1);

		a.signForm(*rrf);
		a.executeForm(*rrf);

		delete rrf;
		std::cout << '\n';
		std::cin.getline(temp, 1);


		std::cout << "---------- Test Presidential Pardon Form ----------\n";

		rrf = someRandomIntern.makeForm("presidential pardon", "home");
		std::cout << *rrf;

		std::cout << '\n';
		std::cin.getline(temp, 1);

		a.signForm(*rrf);
		a.executeForm(*rrf);

		delete rrf;
		std::cout << '\n';
		std::cin.getline(temp, 1);

		std::cout << "---------- Test Other Form ----------\n";

		rrf = someRandomIntern.makeForm("other form", "home");
		delete rrf;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	return 0;
}