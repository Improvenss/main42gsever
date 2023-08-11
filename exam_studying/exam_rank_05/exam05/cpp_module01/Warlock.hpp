#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock( void ); // Default Constructor.
		Warlock( Warlock const &rhs ); // Copy Constructor.
		Warlock &operator=( Warlock const &rhs ); // Copy operator overload.
	public:
		Warlock( const std::string &name, const std::string &title ); // name/title Constructor.
		~Warlock( void ); // Destructor.

		const std::string	&getName( void ) const;
		const std::string	&getTitle( void ) const;

		void	setTitle( std::string const &title );

		void	introduce( void ) const;
};

#endif