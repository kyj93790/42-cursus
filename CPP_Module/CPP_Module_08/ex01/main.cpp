#include <iostream>
#include "Span.hpp"

int main(void) {
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	try {
		std::vector<int> v(10000);
		for (int i=0; i<10000; i++) v[i] = (i+1)*3; // 3 ~ 30000
		Span s(10000);
		
		s.addNumbers(v.begin(), v.end());

		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}

	try {
		std::vector<int> v(6);
		for (int i=0; i<6; i++) v[i] = (i)*2; // 0 2 4 6 8
		Span s(5);
		
		s.addNumbers(v.begin(), v.end());

		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}

	return (0);
}