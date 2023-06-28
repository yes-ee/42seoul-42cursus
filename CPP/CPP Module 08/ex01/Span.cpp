#include "Span.hpp"

Span::Span() {
	this->n = 0;
	std::cout << "default constructor called" << std::endl;
}

Span::Span(unsigned int n) {
	this->n = n;
	std::cout << "N constructor called" << std::endl;
}

Span::~Span() {
	std::cout << "Destructor called" << std::endl;
}

Span::Span(const Span& ref) {
	this->n = ref.n;
	for (unsigned int i = 0; i < n; i++)
		this->v.push_back(ref.v[i]);
	std::cout << "Copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& ref) {
	if (this != &ref) {
	this->n = ref.n;
	v.clear();
	for (unsigned int i = 0; i < n; i++)
		this->v.push_back(ref.v[i]);
	}

void Span::addNumber(int num) {
	if (n == v.size()) {
		throw std::runtime_error("Span is full!");
	}
	this->v.push_back(num);
}
