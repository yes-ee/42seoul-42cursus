#include "Character.hpp"

Character::Character() {
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}

Character::Character(std::string name) {
	this->name = name;
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}

Character::Character(const Character &ref) {
	this->name = ref.name;
	for (int i = 0; i < 4; i++) 
		this->slot[i] = ref.slot[i];
}

Character& Character::operator=(const Character &ref) {
	if (this != &ref) {
		this->name = ref.name;
		for (int i = 0; i < 4; i++)
			this->slot[i] = ref.slot[i];
	}
	return *this;
}

Character::~Character() {
	//slot 돌면서 delete
	for (int i = 0; i < 4; i++) {
		if (slot[i])
			delete slot[i];
	}
}

std::string const& Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i , 4; i++) {
		if (slot[i] == NULL) {
			slot[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	//unequip 하기 전에 주소 저장하기
}

void Character::use(int idx, ICharacter& target) {
	
}