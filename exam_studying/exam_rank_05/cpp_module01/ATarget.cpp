#include "ATarget.hpp"

//ATarget::ATarget(void) {}

ATarget::ATarget( const std::string &type ) : type(type)
{
	std::cout << this->type << ": " << "This looks like another boring day."\
		<< std::endl;
}

ATarget::~ATarget( void )
{
	std::cout << this->type << ": " << "My job here is done!" << std::endl;
}

const std::string	&ATarget::getType( void ) const { return (this->type); }

void	ATarget::getHitBySpell( ASpell const &rhs )
{
	// <TYPE> has been <EFFECTS>!
	std::cout << this->getType() << " has been " << rhs.getEffects()\
		<< "!" << std::endl;
}