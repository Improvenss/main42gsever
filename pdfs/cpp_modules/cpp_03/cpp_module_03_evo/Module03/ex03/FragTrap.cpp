#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	name = "Default";
	hitpoint = 100;
	energy = 100;
	damage = 30;
	std::cout << "FragTrap Default Constructor Called : " << name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitpoint = 100;
	energy = 100;
	damage = 30;
	std::cout << "FragTrap Named Constructor Called : " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& Frag_Copy) : ClapTrap(Frag_Copy)
{
	std::cout << "FragTrap Copy Constructor Called : " << name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& Frag_Copy)
{
	ClapTrap::operator=(Frag_Copy);
	std::cout << "FragTrap Copy Assignment Operator Called : " << name << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor Called : " << name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " positive high fives request!" << std::endl;
}