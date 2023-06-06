#include "MateriaSource.hpp"

MaterialSource::MaterialSource() {
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MaterialSource::~MaterialSource() {
}

MaterialSource::MaterialSource(const MaterialSource &ref) {
	for (int i = 0; i < 4; i++)
		this->materias[i] = ref.materias[i];
}

MaterialSource& MaterialSource::operator=(const MaterialSource &ref) {
	if (this != &ref) {
		for (int i = 0; i < 4; i++)
			this->materias[i] = ref.materias[i];
	}
	return *this;
}

void MaterialSource::learnMateria(AMateria* copy) {
	for (int i = 0; i < 4; i++) {
		if (materias[i] == NULL) {
			materias[i] = copy;
			break;
		}
	}
}

AMateria* MaterialSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (materias[i] && materias[i]->getType() == type) {
			return this->materias[i]->clone();
		}
	}
	return 0;
}