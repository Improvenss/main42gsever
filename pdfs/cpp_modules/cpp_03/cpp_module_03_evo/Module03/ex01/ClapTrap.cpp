#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitpoint(10), energy(10), damage(0)
{
	std::cout << "ClapTrap Default Constructor Called : " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitpoint(10), energy(10), damage(0)
{
	std::cout << "ClapTrap Named Constructor Called : " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& CopyClap) : name(CopyClap.name), hitpoint(CopyClap.hitpoint), energy(CopyClap.energy), damage(CopyClap.damage)
{
	std::cout << "ClapTrap Copy Constructor Called : " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& CopyClap)
{
	name = CopyClap.name;
	hitpoint = CopyClap.hitpoint;
	energy = CopyClap.energy;
	damage = CopyClap.damage;
	std::cout << "ClapTrap Copy Assignment Operator Called : " << name << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor Called : " << name << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
	if(!is_dead())
		return;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
	energy--;
	std::cout << "ClapTrap " << name << " remaining energy point : " << energy << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitpoint <= 0)
	{
		std::cout << "ClapTrap " << name << " already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " has taken " << amount << " points of damage!" << std::endl;
	if (hitpoint <= amount)
	{
		hitpoint = 0;
		std::cout << "ClapTrap " << name << " remaining hit point : " << hitpoint << std::endl;
		std::cout << "ClapTrap " << name << " died!" << std::endl;
	}
	else
	{
		hitpoint -= amount;
		std::cout << "ClapTrap " << name << " remaining hit point : " << hitpoint << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!is_dead())
		return ;
	hitpoint += amount;
	energy--;
	std::cout << "ClapTrap " << name << " has been repaired of " << amount << " hit point!" << std::endl;
	std::cout << "ClapTrap " << name << " remaining hit point : " << hitpoint << std::endl;
	std::cout << "ClapTrap " << name << " remaining energy point : " << energy << std::endl;
}

bool ClapTrap::is_dead() const
{
	if (hitpoint <= 0)
	{
		std::cout << "ClapTrap " << name << " already dead!" << std::endl;
		return false;
	}
	else if (energy <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy point!" << std::endl;
		return false;
	}
	else
		return true;
}

unsigned int ClapTrap::get_damage()
{
	return damage;
}
