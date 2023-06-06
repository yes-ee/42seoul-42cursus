#include "AMateria.hpp"

AMateria::AMateria() {
}

AMateria::AMateria(std::string const &type) {
	this->type = type;
}

AMateria::AMateria(const AMateria &ref) {
	this->type = ref.type();
}

AMateria& AMateria::operator=(const AMateria &ref) {
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

AMateria::~AMateria() {
}

std::string const& AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria use called" << endl;
}