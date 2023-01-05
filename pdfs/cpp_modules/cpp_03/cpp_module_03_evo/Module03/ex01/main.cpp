#include "ScavTrap.hpp"

int main()
{ 
	{
		ClapTrap *a = new ScavTrap();
		ClapTrap *b;
		b = a;
		delete b;
	}
	std::cout << std::endl;
	ScavTrap Default;
	ScavTrap s1("Scav1");
	ScavTrap s2("Scav2");

	std::cout << std::endl;
	s1.attack("Scav2");
	std::cout << std::endl;
	s2.takeDamage(s1.get_damage());
	std::cout << std::endl;
	s2.beRepaired(10);

	std::cout << std::endl;
	s2.guardGate();

	std::cout << std::endl;
	Default.attack("Scav2");
	std::cout << std::endl;
	s2.takeDamage(Default.get_damage());
	std::cout << std::endl;
	return 0;
}