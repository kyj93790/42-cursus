#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try {
		Bureaucrat a("a", 1);
		Bureaucrat b("b", 150);

		Form f1("f1", 1, 1);
		Form f2("f2", 3, 3);

		std::cout << f1 << '\n';
		std::cout << f2 << '\n';

		a.signForm(&f1);
		b.signForm(&f2);
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}