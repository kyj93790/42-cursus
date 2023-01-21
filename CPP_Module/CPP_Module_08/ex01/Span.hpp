#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class Span {
	private:
		unsigned int _maxSize;
		std::vector<int> _v;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span& span);
		Span& operator=(const Span& span);
		void addNumber(int num);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
};

#endif