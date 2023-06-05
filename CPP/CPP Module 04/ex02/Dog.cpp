#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &ref) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = ref.type;
	this->brain = new Brain(*(ref.brain));
}

Dog& Dog::operator=(const Dog &ref) {
	std::cout << "Dog copy assignment constructor called" << std::endl;
	if (this != &ref) {
		this->type = ref.type;
		delete this->brain;
		this->brain = new Brain(*(ref.brain));
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Dog says bowwow" << std::endl;
}