#include "Converter.hpp"

Converter::Converter() {

}

Converter::Converter(std::string arg) {
	_errFlag = false;
	_input = arg;
	convertToDouble();
}

Converter::Converter(const Converter& converter) {
	(*this) = converter;
}

Converter::~Converter() {

}

const Converter& Converter::operator=(const Converter& converter) {
	_input  = converter._input;
	_d = converter._d;
	_errFlag = converter._errFlag;
	return (*this);
}

void Converter::printChar() {
	std::cout << "char: ";
	if (isNan() || _input == "impossible" || _d < CHAR_MIN || _d > CHAR_MAX) std::cout << "impossible";
	else if (isprint(static_cast<char>(_d))) std::cout << "'" << static_cast<char>(_d) << "'";
	else std::cout << "Non displayable";
	std::cout << '\n';
}

void Converter::printInt() {
	std::cout << "int: ";
	if (isNan() || _input == "impossible" || _d < INT_MIN || _d > INT_MAX) std::cout << "impossible";
	else std::cout << static_cast<int>(_d);
	std::cout << '\n';
}

void Converter::printFloat() {
	std::cout << "float: ";
	if (isNan()) std::cout << "nanf";
	else if (_input == "impossible") std::cout << "impossible";
	else {
		std::cout << static_cast<float>(_d);
		if (_d - static_cast<int>(_d) <= 1e-6) std::cout << ".0";
		std::cout << 'f';
	}
	std::cout << '\n';
}

void Converter::printDouble() {
	std::cout << "double: ";
	if (isNan()) std::cout << "nan";
	else if (_input == "impossible") std::cout << "impossible";
	else {
		std::cout << _d;
		if (_d - static_cast<int>(_d) <= 1e-6) std::cout << ".0";
	}
	std::cout << '\n';
}

void Converter::convertToDouble() {
	char *pEnd;
	
	_d = strtod(_input.c_str(), &pEnd);
	if (errno == ERANGE) _errFlag = true;												// overflow, underflow
	if (pEnd != _input.c_str() + _input.length()) {										// remain part exist
		if (pEnd == _input.c_str()) {													// prefix integer doesn't exist
			if (((std::string)pEnd).length() == 1) _d = static_cast<double>(*pEnd);
			else _d = strtod("nan", &pEnd);
		} else {																		// prefix integer exist
			if ((std::string)pEnd != "f") _d = strtod("nan", &pEnd);
		}
	}
	if (_errFlag) _input = "impossible";
}

bool Converter::isNan() {
	if (_d != _d) return true;
	else return false;
}

void Converter::printAll() {
	printChar();
	printInt();
	printFloat();
	printDouble();
}