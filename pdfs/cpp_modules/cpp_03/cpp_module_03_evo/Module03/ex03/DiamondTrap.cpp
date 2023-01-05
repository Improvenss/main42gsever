#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), name(ClapTrap::name)
{
	ClapTrap::name += "_clap_name";
	hitpoint = FragTrap::hitpoint;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
	std::cout << "DiamondTrap Default Constructor Called : " << name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name), name(name)
{
	ClapTrap::name += "_clap_name";
	hitpoint = FragTrap::hitpoint;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
	std::cout << "DiamondTrap Named Constructor Called : " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& Diamond_Copy) : ClapTrap(Diamond_Copy), FragTrap(Diamond_Copy), ScavTrap(Diamond_Copy), name(Diamond_Copy.name)
{
	std::cout << "DiamondTrap Copy Constructor Called : " << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& Diamond_Copy)
{
	ClapTrap::operator=(Diamond_Copy);
	std::cout << "DiamondTrap Copy Assignment Operator Called : " << name << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor Called : " << name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::name << std::endl;
}