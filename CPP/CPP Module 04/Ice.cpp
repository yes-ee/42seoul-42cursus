#include "Ice.hpp"

Ice::Ice() {
	this->type = "ice";
}

Ice::Ice(const Ice &ref) {
	this->type = ref.type;
}

Ice& Ice::operator=(const Ice &ref) {
	if (this != &ref)
			this->type = ref.type;
	return *this;
}

Ice::~Ice() {
}

AMateria* Ice::clone() const {
	Ice *i = new Ice();
	return i;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}