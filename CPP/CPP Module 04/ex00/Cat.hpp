#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &ref);
		Cat &operator=(const Cat &ref);
		~Cat();
		void makeSound() const;
};

#endif