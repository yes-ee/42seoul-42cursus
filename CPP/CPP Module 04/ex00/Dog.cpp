#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &ref) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = ref.type;
}

Dog& Dog::operator=(const Dog &ref) {
	std::cout << "Dog copy assignment constructor called" << std::endl;
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Dog says bowwow" << std::endl;
}