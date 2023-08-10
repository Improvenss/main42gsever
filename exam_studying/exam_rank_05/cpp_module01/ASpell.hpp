#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>

class ATarget;

class ASpell
{
	private:
		std::string	name;
		std::string	effects;

	public:
		ASpell( void ); // Constructor
		ASpell( const std::string &name, const std::string &effects ); // Name constructor.
		ASpell( ASpell const &rhs ); // Copy constructor.
		ASpell &operator=( ASpell const &rhs ); // Copy assignment operator overload.
		virtual ~ASpell( void ); // Destructor.

		const std::string	&getName( void ) const;
		const std::string	&getEffects( void ) const;

		void launch( ATarget const &atarget_ref ) const;

		virtual ASpell	*clone() const = 0;
};

# include <ATarget.hpp>

#endif
