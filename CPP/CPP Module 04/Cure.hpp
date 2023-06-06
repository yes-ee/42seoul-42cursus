#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &ref);
		Cure &operator=(const Cure &ref);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
