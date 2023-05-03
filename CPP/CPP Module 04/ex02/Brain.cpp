#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "idea";
}

Brain::Brain(const Brain &ref) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ref.ideas[i];
}

Brain& Brain::operator=(const Brain &ref) {
	std::cout << "Brain copy assignment called" << std::endl;
	if (this != &ref) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = ref.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

std::string *Brain::getIdeas() {
	return this->ideas;
}
