#ifndef IMATERIALSOURCE_HPP
# define IMATERIALSOURCE_HPP

# include <string>
# include "AMateria.hpp"

class IMaterialSource {
	public:
		virtual ~IMaterialSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const &type) = 0;
};

#endif
