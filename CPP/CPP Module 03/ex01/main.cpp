#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("A");
	ScavTrap b("B");

	a.attack("B");
	b.takeDamage(10);
	b.beRepaired(3);
	b.attack("A");
	a.takeDamage(10);
	a.guardGate();	
	a.beRepaired(10);
	return (0);
}