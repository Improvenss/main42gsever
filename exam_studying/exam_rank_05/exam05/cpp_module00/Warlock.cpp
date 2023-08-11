#include "Warlock.hpp"

Warlock::Warlock( const std::string &name, const std::string &title )\
	: name(name), title(title)
{
	// <NAME>: This looks like another boring day.
	std::cout << this->name << ": This look like another boring day."\
		<< std::endl;
}

Warlock::~Warlock( void )
{
	// <NAME>: My job here is done!
	std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string	&Warlock::getName( void ) const { return (this->name); }

const std::string	&Warlock::getTitle( void ) const { return (this->title); }

void	Warlock::setTitle( const std::string &title ) { this->title = title; }

void	Warlock::introduce( void ) const
{
	// <NAME>: I am <NAME>, <TITLE>!
	std::cout << this->getName() << ": I am " << this->getName() << ", "\
		<< this->getTitle() << "!" << std::endl;
}