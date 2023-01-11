/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:54:42 by gsever            #+#    #+#             */
/*   Updated: 2023/01/11 13:35:17 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::flush << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.\
I really do!" << std::flush << std::endl;
	std::cout << std::flush << std::endl;
}
void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::flush << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\n\
You didn’t put enough bacon in my burger!\n\
If you did, I wouldn’t be asking for more!" << std::flush << std::endl;
	std::cout << std::flush << std::endl;
}
void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::flush << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\n\
I’ve been coming for years whereas you started working here since last month." << std::flush << std::endl;
	std::cout << std::flush << std::endl;
}
void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::flush << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::flush << std::endl;
	std::cout << std::flush << std::endl;
}

void	Harl::complain( std::string level )
{
	int	index;

	// t_funcPointer	t_classFuncs[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string		t_classFuncIndex[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	index = 0;
	while (index < 4 && t_classFuncIndex[index].compare(level))
		index++;
		switch (index)
		{
			case (0):
				this->debug();
			case (1):
				this->info();
			case (2):
				this->warning();
			case (3):
				this->error();
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::flush << std::endl;
				break;
		}
	// if (index < 4)// 0, 1, 2, 3
		// (this->*t_classFuncs[index])();
}