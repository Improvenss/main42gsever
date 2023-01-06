#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	{
		std::cout << std::endl;
		ClapTrap *a = new DiamondTrap();
		ClapTrap *b;
		b = a;
		delete b;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		DiamondTrap d;
  	  	ClapTrap *b1 = &d;
   		ClapTrap *b2 = &d;
		(void)b1;
		(void)b2;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		DiamondTrap d1("Diamond1");
		std::cout << std::endl;
		DiamondTrap d2("Diamond2");
		std::cout << std::endl;
		DiamondTrap d3;

		std::cout << std::endl;
		d1.whoAmI();

		std::cout << std::endl;
		d2.guardGate();

		std::cout << std::endl;
		d3.highFivesGuys();

		std::cout << std::endl;
		d1.attack("Diamond2");

		std::cout << std::endl;
		d2.takeDamage(d1.get_damage());

		std::cout << std::endl;
		d2.attack("Diamond3");

		std::cout << std::endl;
		d3.takeDamage(d2.get_damage());
		std::cout << std::endl;
	}
	return 0;
}