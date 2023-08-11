#include "ASpell.hpp"

//ASpell::ASpell(void) {}

ASpell::ASpell( const std::string &name, const std::string &effects)
	: name(name), effects(effects)
{
	std::cout << this->name << ": " << "This looks like another boring day."\
		<< std::endl;
}

ASpell::~ASpell( void )
{
	std::cout << this->name << ": " << "My job here is done!" << std::endl;
}

const std::string	&ASpell::getName( void ) const { return (this->name); }

const std::string	&ASpell::getEffects( void ) const { return (this->effects); }

void	ASpell::launch( ATarget const &rhs )
{
	rhs.getHitBySpell(*this);
}