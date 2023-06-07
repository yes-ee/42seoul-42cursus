#include "Cure.hpp"

Cure::Cure() {
	this->type = "cure";
}

Cure::Cure(const Cure &ref) {
	this->type = ref.type;
}

Cure& Cure::operator=(const Cure &ref) {
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

Cure::~Cure() {
}

AMateria* Cure::clone() const {
	Cure *c = new Cure();
	return c;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}