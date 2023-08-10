# include "ASpell.hpp"

// Constructor.
ASpell::ASpell( void ) {}

// Name Constructor.
ASpell::ASpell( const std::string &name, const std::string &effects )\
	: name(name), effects(effects) {}

// Copy Constructor.
ASpell::ASpell( ASpell const &rhs ) { *this = rhs; }

// Destructor
ASpell::~ASpell( void )
{
	std::cout << this->name << " : " << "My job here is done!" << std::endl;
}

// Copy assignment operator overload.
ASpell	&ASpell::operator=( ASpell const &rhs )
{

}

const std::string	&ASpell::getName( void ) const { return (this->name); }

const std::string	&ASpell::getEffects( void ) const { return (this->effects); }
