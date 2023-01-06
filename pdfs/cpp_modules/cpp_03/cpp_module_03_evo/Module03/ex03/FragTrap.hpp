#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& Frag_Copy);
	FragTrap& operator=(const FragTrap& Frag_Copy);
	virtual ~FragTrap();

	void highFivesGuys(void);
};


#endif