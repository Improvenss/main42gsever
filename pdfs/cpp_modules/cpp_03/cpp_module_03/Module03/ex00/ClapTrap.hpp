#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include<iostream>

class ClapTrap
{
private:
	std::string name;
	unsigned int hitpoint;
	unsigned int energy;
	unsigned int damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& CopyClap);
	ClapTrap& operator=(const ClapTrap& CopyClap);
	~ClapTrap();
	

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	bool is_dead() const;
	void set_damage(unsigned int amount);
};


#endif