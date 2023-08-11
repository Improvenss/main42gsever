#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock
{
	private:
		std::string	name;
		std::string	title;
		Warlock( void ); // Default Constructor.
		Warlock( const Warlock &rhs ); // Copy Constructor.
		Warlock	&operator=( const Warlock &rhs ); // Copy assignment operator overload.
	public:
		Warlock( const std::string &name, const std::string &title ); // Name Constructor.
		~Warlock( void ); // Destructor.
		const std::string	&getName( void ) const;
		const std::string	&getTitle( void ) const;

		void	setTitle( const std::string &title );

		void	introduce( void ) const;
};

#endif
