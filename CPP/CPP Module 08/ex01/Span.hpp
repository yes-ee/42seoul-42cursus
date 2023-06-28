#ifndef Span_HPP
# define Span_HPP

# include <iostream>
# include <vector>
# include <stdexcept>

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
		int shortestSpan();
		int longestSpan();
};

#endif