#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat a("a", 1);
		Bureaucrat b("b", 2);
		Bureaucrat c("c", 150);
		Bureaucrat d("d", 160);
		Bureaucrat e("e", -1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	return 0;
}