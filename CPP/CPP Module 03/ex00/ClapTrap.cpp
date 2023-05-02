#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
	this->name = "";
	this->hit = 10;
	this->energy = 10;
	this->damage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << name << " constructor called" << std::endl;
	this->name = name;
	this->hit = 10;
	this->energy = 10;
	this->damage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << this->name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref) {
	std::cout << ref.name << " copy constructor called" << std::endl;
	this->name = ref.name;
	this->hit = ref.hit;
	this->energy = ref.energy;
	this->damage = ref.damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref) {
	std::cout << ref.name << " copy assignment operator called" << std::endl;
	if (this != &ref) {
		this->name = ref.name;
		this->hit = ref.hit;
		this->energy = ref.energy;
		this->damage = ref.damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (this->energy == 0 || this->hit == 0)
		std::cout << "ClapTrap " << this->name << " can't do anything" << std::endl;
	else {
		this->energy--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy == 0 || this->hit == 0)
		std::cout << "ClapTrap " << this->name << " can't do anything" << std::endl;
	else {
		this->energy--;
		this->hit += amount;
		std::cout << "ClapTrap " << this->name << " has been repaired. Now hit point is " << this->hit << " ." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > this->hit)
		this->hit = 0;
	else
		this->hit -= amount;
	std::cout << "ClapTrap " << this->name << " has taken damage. Now hit point is " << this->hit << " ." << std::endl;
}