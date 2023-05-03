#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = ref.type;
}

WrongCat& WrongCat::operator=(const WrongCat &ref) {
	std::cout << "WrongCat copy assignment constructor called" << std::endl;
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

void WrongCat::makeSound() const{
	std::cout << "WrongCat says meow" << std::endl;
}