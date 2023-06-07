#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (materias[i])
			delete materias[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &ref) {
	for (int i = 0; i < 4; i++)
		this->materias[i] = ref.materias[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource &ref) {
	if (this != &ref) {
		for (int i = 0; i < 4; i++)
			if (this->materias[i])
				this->materias[i] = ref.materias[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* copy) {
	for (int i = 0; i < 4; i++) {
		if (materias[i] == NULL) {
			materias[i] = copy;
			return;
		}
	}
	std::cout << "cannot learn Materia" << std::endl;
	delete copy;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (materias[i] && materias[i]->getType() == type) {
			return this->materias[i]->clone();
		}
	}
	std::cout << "materia " << type << " not exist" << std::endl;
	return 0;
}