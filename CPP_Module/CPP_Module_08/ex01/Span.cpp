#include "Span.hpp"

Span::Span() { };

Span::Span(unsigned int n) {
	_maxSize = n;
}

Span::Span(const Span& span) {
	(*this) = span;
}

Span& Span::operator=(const Span& span) {
	_maxSize = span._maxSize;
	_v = span._v;
	return (*this);
}

void Span::addNumber(int num) {
	if (_v.size() == _maxSize) throw std::out_of_range("Error: container is full");
	_v.push_back(num);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	std::vector<int>::iterator it = begin;

	for (; it != end; ++it)
		addNumber(*it);
}

int Span::shortestSpan() {
	if (_v.size() < 2) throw std::runtime_error("Error: span can't be found");
	
	std::vector<int> v(_v);
	std::vector<int>::iterator it;
	int shortestSpan;

	sort(v.begin(), v.end());
	shortestSpan = v.back() - v.front();
	for (it = v.begin()+1; it != v.end(); ++it) {
		shortestSpan = std::min(shortestSpan, *it - *(it-1));
	}
	return shortestSpan;
}

int Span::longestSpan() {
	if (_v.size() < 2) throw std::runtime_error("Error: span can't be found");

	std::vector<int> v(_v);

	sort(v.begin(), v.end());
	return (v.back() - v.front());
}
