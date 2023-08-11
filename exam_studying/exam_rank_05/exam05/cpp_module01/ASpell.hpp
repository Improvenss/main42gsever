#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <map>

class ASpell
{
	private:
		std::string name;
		std::string effects;
	public:
		ASpell( void ); // Default Constructor.
		ASpell( const std::string &name, const std::string &effects ); // name/effects Constructor.
		ASpell( ASpell const &rhs ); // Copy Constructor.
		ASpell &operator=( ASpell const &rhs ); // Copy operator overload.
		virtual	~ASpell( void ); // Destructor.

		const std::string	&getName( void ) const;
		const std::string	&getEffects( void ) const;

		virtual	ASpell &clone( void ) const = 0;
};

#endif