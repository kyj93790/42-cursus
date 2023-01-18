#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void) {
	srand(time(NULL));
	Base *b = generate();

	identify(b);
	identify(*b);

	delete b;
	return (0);
}

Base *generate(void) {
	Base *base;
	int randVal = rand() % 3;

	switch (randVal) {
		case 0:
			base = new A();
			std::cout << "generate type : A\n";
			break;
		case 1:
			base = new B();
			std::cout << "generate type : B\n";
			break;
		case 2:
			base = new C();
			std::cout << "generate type : C\n";
			break;
		default:
			base = NULL;
	}
	return base;
}

void identify(Base *p) {
	A *aPtr;
	B *bPtr;
	C *cPtr;
	std::string type;

	aPtr = dynamic_cast<A *>(p);
	bPtr = dynamic_cast<B *>(p);
	cPtr = dynamic_cast<C *>(p);
	if (aPtr) type = "A";
	if (bPtr) type = "B";
	if (cPtr) type = "C";

	std::cout << "Actual type of the object : " << type << '\n';
}

void identify(Base& p) {
	std::string type;
	try {
		A &aRef = dynamic_cast<A &>(p);
		(void)aRef;
		type = "A";
	} catch (std::exception &e) {
		try {
			B &bRef = dynamic_cast<B &>(p);
			(void)bRef;
			type = "B";
		}
		catch (std::exception &e) {
			C &cRef = dynamic_cast<C &>(p);
			(void)cRef;
			type = "C";
		}
	}
	std::cout <<  "Actual type of the object : " << type << '\n';
}