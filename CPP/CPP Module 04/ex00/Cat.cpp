#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &ref) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = ref.type;
}

Cat& Cat::operator=(const Cat &ref) {
	std::cout << "Cat copy assignment constructor called" << std::endl;
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

void Cat::makeSound() const{
	std::cout << "Cat says meow" << std::endl;
}