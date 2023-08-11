#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string	type;
	public:
		ATarget( void ); // Default Constructor.
		ATarget( const std::string &type ); // Name Constructor.
		ATarget( const ATarget &rhs ); // Copy Constructor.
		ATarget	&operator=( const ATarget &rhs ); // Copy assignment operator overload.
		virtual	~ATarget( void ); // Destructor.

		const std::string	&getType( void ) const;

		virtual	ATarget	*clone( void ) const = 0;

		void	getHitBySpell( ASpell const &rhs );
};

#endif
