#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include<iostream>

class ClapTrap
{
protected:
	std::string name;
	unsigned int hitpoint;
	unsigned int energy;
	unsigned int damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& CopyClap);
	ClapTrap& operator=(const ClapTrap& CopyClap);
	virtual ~ClapTrap();
	

	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	unsigned int get_damage();
	bool is_dead() const;
};


#endif