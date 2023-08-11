#include "ASpell.hpp"

// Default Destructor.
ASpell::ASpell( void ) {}

// name/effects operator.
ASpell::ASpell( const std::string &name , const std::string &effects )
	: name(name), effects(effects) {}

// Copy Destructor.
ASpell::ASpell( ASpell const &rhs ) { *this = rhs; }

// Copy assignmen operator overload.
ASpell	&ASpell::operator=( ASpell const &rhs )
{
	this->name = rhs.getName();
	this->effects = rhs.getEffects();
	return (*this);
}

// Destructor.
ASpell::~ASpell( void ) {}

// Getting name inside ASpell.
const std::string	&ASpell::getName( void ) const { return (this->name); }

// Getting effects inside ASpell.
const std::string	&ASpell::getEffects( void ) const { return (this->effects); }

