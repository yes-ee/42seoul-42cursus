#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal {
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &ref);
		Cat &operator=(const Cat &ref);
		~Cat();
		void makeSound() const;
};

#endif