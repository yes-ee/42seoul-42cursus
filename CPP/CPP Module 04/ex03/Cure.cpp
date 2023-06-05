#include "Cure.hpp"

Cure::Cure() {
	this->type = "Cure";
}

Cure::~Cure() {
}

AMateria* Cure::clone() const {
	Cure *c = new Cure();
	return c;
}