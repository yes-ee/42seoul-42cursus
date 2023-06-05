#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;	
}

Cat::Cat(const Cat &ref) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = ref.type;
	this->brain = new Brain(*(ref.brain));
}

Cat& Cat::operator=(const Cat &ref) {
	std::cout << "Cat copy assignment constructor called" << std::endl;
	if (this != &ref) {
		this->type = ref.type;
		delete this->brain;
		this->brain = new Brain(*(ref.brain));
	}
	return *this;
}

void Cat::makeSound() const{
	std::cout << "Cat says meow" << std::endl;
}