#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    Span tmp = Span(1000);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    tmp.fillSpan();

    std::cout << tmp.shortestSpan() << std::endl;
    std::cout << tmp.longestSpan() << std::endl;

    return 0;
}