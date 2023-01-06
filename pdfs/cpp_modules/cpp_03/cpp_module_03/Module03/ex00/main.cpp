#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap c1("Fatma");
	ClapTrap c2("Ozturk");
	ClapTrap c3(c1);
	ClapTrap c4 = c2;
	c3 = c4;

	std::cout << std::endl;
	while (c1.is_dead() && c2.is_dead())
	{
		c1.attack("Ozturk");
		c1.set_damage(2);
		c2.takeDamage(2);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	c1.beRepaired(10);
	std::cout << std::endl;
	
	return 0;
}
