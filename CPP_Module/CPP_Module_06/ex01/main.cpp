# include "Data.hpp"
# include "Serializer.hpp"

# include <iostream>

int main(void) {
	Data *a;
	uintptr_t b;
	Serializer s;

	a = new Data("a", 1);
	std::cout << "original ptr : " << a << '\n';
	b = s.serialize(a);
	std::cout << "serialized ptr : " << b << '\n';
	a = s.deserialize(b);
	std::cout << "deserialized ptr : " << a << '\n';

	delete a;
	return (0);
}