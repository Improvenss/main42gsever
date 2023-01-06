#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	{
		std::cout << std::endl;
		ClapTrap *a = new ScavTrap();
		ClapTrap *b;
		b = a;
		delete b;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		FragTrap d;
  	  	ClapTrap *b1 = &d;
   		ClapTrap *b2 = &d;
		(void)b1;
		(void)b2;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	ClapTrap Default;
	ScavTrap s1("Scav1");
	FragTrap f1("Frag1");

	std::cout << std::endl;
	s1.attack("Frag1");
	
	std::cout << std::endl;
	f1.takeDamage(s1.get_damage());

	std::cout << std::endl;
	s1.guardGate();

	std::cout << std::endl;
	f1.attack("Scav1");

	std::cout << std::endl;
	s1.takeDamage(f1.get_damage());

	std::cout << std::endl;
	Default.beRepaired(100);

	std::cout << std::endl;
	f1.highFivesGuys();
	std::cout << std::endl;
	return 0;
}