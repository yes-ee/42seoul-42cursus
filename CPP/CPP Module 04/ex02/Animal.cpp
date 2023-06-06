#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &ref) {
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = ref.type;
}

Animal& Animal::operator=(const Animal &ref) {
	std::cout << "Animal copy assignment constructor called" << std::endl;
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

std::string Animal::getType() const {
	return this->type;
}
