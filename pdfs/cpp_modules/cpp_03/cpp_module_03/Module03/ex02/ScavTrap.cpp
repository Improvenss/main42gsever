#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	name = "Default";
	hitpoint = 100;
	energy = 50;
	damage = 20;
	guard_mode = false;
	std::cout << "ScavTrap Default Constructor Called : " << name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitpoint = 100;
	energy = 50;
	damage = 20;
	guard_mode = false;
	std::cout << "ScavTrap Named Constructor Called : " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& Scav_Copy) : ClapTrap(Scav_Copy)
{
	guard_mode = Scav_Copy.guard_mode;
	std::cout << "ScavTrap Copy Constructor Called : " << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& Scav_Copy)
{
	ClapTrap::operator=(Scav_Copy);
	guard_mode = Scav_Copy.guard_mode;
	std::cout << "ScavTrap Copy Assignment Operator Called : " << name << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called : " << name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(!is_dead())
		return;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
	energy--;
	std::cout << "ScavTrap " << name << " remaining energy point : " << energy << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (guard_mode)
		std::cout << "ScavTrap " << name << " can't be attacked because it is in guard gate mode!" << std::endl;
	else
		ClapTrap::takeDamage(amount);
}

void ScavTrap::guardGate(void)
{
	if (hitpoint > 0)
	{
		guard_mode = true;
		std::cout << "ScavTrap " << name << " is now in guard gate mode" << std::endl;
	}
	else
		std::cout << "ScavTrap " << name << " guard gate mode close because of dead!" << std::endl;
}
