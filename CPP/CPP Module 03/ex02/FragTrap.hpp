#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : public ClapTrap{
	public:
		FragTrap();
		FragTrap(std::string s);
		FragTrap(const FragTrap &ref);
		FragTrap &operator=(const FragTrap &ref);
		~FragTrap();
		void highFivesGuys();
};

#endif