#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "";
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
	this->name = name;
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::~FragTrap() {
		std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) {
	std::cout << ref.name << " copy constructor called" << std::endl;
	this->name = ref.name;
	this->hit = ref.hit;
	this->energy = ref.energy;
	this->damage = ref.damage;
}

FragTrap& FragTrap::operator=(const FragTrap& ref) {
	std::cout << ref.name << " copy assignment operator called" << std::endl;
	if (this != &ref) {
		this->name = ref.name;
		this->hit = ref.hit;
		this->energy = ref.energy;
		this->damage = ref.damage;
	}
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << this->name << " high five" << std::endl;
}
