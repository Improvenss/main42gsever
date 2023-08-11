#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
		std::string	name;
		std::string	effects;
	public:
		ASpell( void ); // Default Constructor.
		ASpell( const std::string &name, const std::string &title ); // Name Constructor.
		ASpell( const ASpell &rhs ); // Copy Constructor.
		ASpell	&operator=( const ASpell &rhs ); // Copy assignment operator overload.
		virtual	~ASpell( void ); // Destructor.

		const std::string	&getName( void ) const;
		const std::string	&getEffects( void ) const;

		virtual	ASpell	*clone( void ) const = 0;

		void	launch( ATarget const &rhs );
};

#endif
