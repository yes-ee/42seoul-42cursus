#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->type = ref.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &ref) {
	std::cout << "WrongAnimal copy assignment constructor called" << std::endl;
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Animal says ?" << std::endl;
}