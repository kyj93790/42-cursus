#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <sstream>
# include <cstdlib>
# include <iostream>
# include <climits>
# include <cfloat>

class Converter {
	private:
		std::string _input;
		double _d;
		bool _errFlag;
		Converter();
		void convertToDouble();
		void printChar();
		void printInt();
		void printFloat();
		void printDouble();
		bool isNan();
		bool isInf();
	public:
		Converter(std::string arg);
		Converter(const Converter& converter);
		~Converter();
		const Converter& operator=(const Converter& converter);
		void printAll();
};

#endif