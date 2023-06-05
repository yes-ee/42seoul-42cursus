#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *meta[10];

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << meta[3]->getType() << " " << std::endl;
	meta[3]->makeSound();
	std::cout << meta[6]->getType() << " " << std::endl;
	meta[6]->makeSound();

	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		delete meta[i];
		std::cout << std::endl;
	}

	return 0;
}
