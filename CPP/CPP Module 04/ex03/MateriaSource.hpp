#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
	private:
		AMateria *materias[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &ref);
		MateriaSource &operator=(const MateriaSource &ref);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type);
};

#endif
