#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter{
	private:
		AMateria* slot[4];
		AMateria* floor[10];
		std::string name;
		void putFloor(AMateria* m);
	public:
		Character();
		Character(std::string name);
		Character(const Character &ref);
		Character &operator=(const Character &ref);
		~Character();
		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
