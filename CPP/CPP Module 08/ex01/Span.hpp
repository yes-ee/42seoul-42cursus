#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <stdexcept>
# include <cstdlib>
# include <algorithm>

class Span {
	private:
		unsigned int n;
		std::vector<int> v;

	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span(const Span& ref);
		Span& operator=(const Span& ref);

		void addNumber(int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void fillSpan();
		unsigned int getLength();
};

#endif