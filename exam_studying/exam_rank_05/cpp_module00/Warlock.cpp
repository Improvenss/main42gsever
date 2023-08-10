# include "Warlock.hpp"

//Warlock::Warlock( void ) {}

Warlock::Warlock( const std::string &name, const std::string &title ) : name(name), title(title)
{
	std::cout << this->name << " : " << "This looks like another boring day." << std::endl;
}

Warlock::~Warlock( void )
{
	std::cout << this->name << " : " << "My job here is done!" << std::endl;
}

const std::string	&Warlock::getName( void ) const { return (this->name); }

const std::string	&Warlock::getTitle( void ) const { return (this->title); }

void	Warlock::setTitle( const std::string &title ) { this->title = title; }

void	Warlock::introduce() const
{
	std::cout << this->getName() << " : " << "I am " << this->getName() \
		<< ", " << this->getTitle() << "!" << std::endl;
	//std::cout << this->name << " : " << "I am " << this->name << ", " << this->title << "!" << std::endl;
}
