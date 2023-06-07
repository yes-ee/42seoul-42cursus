#include "Character.hpp"

Character::Character() {
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
	for (int i = 0; i < 10; i++)
		floor[i] = NULL;
}

Character::Character(std::string name) {
	this->name = name;
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
	for (int i = 0; i < 10; i++)
		floor[i] = NULL;
}

Character::Character(const Character &ref) {
	this->name = ref.name;
	for (int i = 0; i < 4; i++)
		if (ref.slot[i])
			this->slot[i] = ref.slot[i]->clone();
	for (int i = 0; i < 10; i++)
		if (ref.floor[i])
			this->floor[i] = ref.floor[i]->clone();
}

Character& Character::operator=(const Character &ref) {
	if (this != &ref) {
		this->name = ref.name;
		for (int i = 0; i < 4; i++)
			if (ref.slot[i])
				this->slot[i] = ref.slot[i]->clone();
		for (int i = 0; i < 10; i++)
			if (ref.floor[i])
				this->floor[i] = ref.floor[i]->clone();
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (slot[i])
			delete slot[i];
	}
	for (int i = 0; i < 10; i++) {
		if (floor[i])
			delete floor[i];
	}
}

std::string const& Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	if (m == NULL) {
		std::cout << "cannot equip" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (slot[i] == NULL) {
			slot[i] = m;
			return;
		}
	}
	std::cout<< "cannot equip: not enough slot" << std::endl;
	putFloor(m);
}

void Character::putFloor(AMateria* m) {
	for (int i = 0; i < 10; i++) {
		if (floor[i]) {
			floor[i] = m;
			return;
		}
	}
	for (int i = 0; i < 10; i++)
		delete floor[i];
	floor[0] = m;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3 && slot[idx])
	{
		putFloor(slot[idx]);
		slot[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <=3 && slot[idx])
		slot[idx]->use(target);
}