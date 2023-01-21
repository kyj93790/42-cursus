#include <iostream>
#include "easyfind.hpp"

#include <vector>
#include <list>

int main(void) {
	try {
		std::vector<int> v;
		std::vector<int>::iterator it;

		v.push_back(2);
		v.push_back(4);
		v.push_back(6);
		v.push_back(8);
		v.push_back(10);

		it = easyfind(v, 4);
		std::cout << *it << '\n';
		it = easyfind(v, 3);
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}

	try {
		std::list<int> l;
		std::list<int>::iterator it;

		l.push_back(2);
		l.push_back(4);
		l.push_back(6);
		l.push_back(8);
		l.push_back(10);

		it = easyfind(l, 10);
		std::cout << *it << '\n';
		it = easyfind(l, 7);
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}

	return (0);
}