#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal {
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &ref);
		Dog &operator=(const Dog &ref);
		~Dog();
		void makeSound() const;
};

#endif