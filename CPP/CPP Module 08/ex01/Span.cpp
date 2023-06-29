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
	return *this;
}

void Span::addNumber(int num) {
	if (n == v.size()) {
		throw std::runtime_error("Span is full!");
	}
	this->v.push_back(num);
}

unsigned int Span::shortestSpan() {
	if (v.size() < 2)
		throw std::runtime_error("Element is not enough");

	std::vector<int> tmp(v);
	unsigned int min = 4294967295;
	unsigned int diff;
	

	sort(tmp.begin(), tmp.end());

	for (std::vector<int>::iterator iter = tmp.begin() + 1; iter != tmp.end(); iter++) {
		diff = (*iter) - *(iter - 1);
		if (diff < min)
			min = diff;
	}

	return min;
}

unsigned int Span::longestSpan() {
	if (v.size() < 2)
		throw std::runtime_error("Element is not enough");

	std::vector<int> tmp(v);

	sort(tmp.begin(), tmp.end());

	return (tmp[n-1] - tmp[0]);
}

int func() {
	return rand() % 1000;
}

void Span::fillSpan() {
	srand(time(NULL));
	std::vector<int> buf(n);
	std::generate(buf.begin(), buf.end(), func);
	v = buf;
}

unsigned int Span::getLength() {
	return this->n;
}
