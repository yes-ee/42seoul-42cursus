#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <string>

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(const AMateria &ref);
		AMateria(std::string const &type);
		AMateria &operator=(const AMateria &ref);
		~AMateria();
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;	//ice, cure에서 구현
		virtual void use(ICharacter& target);	//파생 클래스에서 오버라이딩 해서 사용
};

#endif
