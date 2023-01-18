#include <string>
#include <iostream>

#include "Converter.hpp"

int main(int argc, char *argv[])
{
	if (argc > 2) {
		std::cout << "Argument error\n";
		return (0);
	}

	Converter converter(argv[1]);
	converter.printAll();

	return (0);
}