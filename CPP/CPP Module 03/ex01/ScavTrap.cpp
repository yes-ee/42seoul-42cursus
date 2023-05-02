#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name = "";
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
	this->name = name;
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::~ScavTrap() {
		std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref) {
	std::cout << ref.name << " copy constructor called" << std::endl;
	this->name = ref.name;
	this->hit = ref.hit;
	this->energy = ref.energy;
	this->damage = ref.damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref) {
	std::cout << ref.name << " copy assignment operator called" << std::endl;
	if (this != &ref) {
		this->name = ref.name;
		this->hit = ref.hit;
		this->energy = ref.energy;
		this->damage = ref.damage;
	}
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << this->name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->energy == 0 || this->hit == 0)
		std::cout << "ScavTrap " << this->name << " can't do anything" << std::endl;
	else {
		this->energy--;
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
	}
}