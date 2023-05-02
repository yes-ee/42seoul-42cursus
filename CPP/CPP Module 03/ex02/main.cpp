#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	// ScavTrap a("A");
	// ScavTrap b("B");
	FragTrap c("C");
	FragTrap d("D");

	// a.attack("B");
	// b.takeDamage(10);
	// b.beRepaired(3);
	// b.attack("A");
	// a.takeDamage(10);
	// a.guardGate();	
	// a.beRepaired(10);

	c.attack("D");
	d.takeDamage(10);
	d.beRepaired(3);
	d.attack("C");
	c.takeDamage(10);
	c.highFivesGuys();
	return (0);
}