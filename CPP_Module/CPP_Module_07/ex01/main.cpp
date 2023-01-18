#include "iter.hpp"
#include <iostream>

int main(void) {
	int intArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char charArr[5] = {'a', 'b', 'c', 'd', 'e'};

	iter(intArr, 10, up);
	iter(intArr, 10, print);
	std::cout << '\n';

	iter(charArr, 5, up);
	iter(charArr, 5, print);
	std::cout << '\n';

	return (0);
}