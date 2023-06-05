//IMateriaSource 인터페이스를 상속받는 클래스

#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP

# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class MaterialSource {
	private:
		AMateria *materias[4];
	public:
		MaterialSource();
		~MaterialSource();
		MaterialSource(const MaterialSource &ref);
		MaterialSource &operator=(const MaterialSource &ref);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const &type);
};

#endif
