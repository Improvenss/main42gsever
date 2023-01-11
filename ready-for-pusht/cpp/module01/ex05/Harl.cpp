/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:54:42 by gsever            #+#    #+#             */
/*   Updated: 2023/01/03 17:44:05 by gsever           ###   ########.fr       */
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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::flush << std::endl;
}
void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::flush << std::endl;
}
void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::flush << std::endl;
}
void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::flush << std::endl;
}

void	Harl::complain( std::string level )
{
	int	index;

	t_funcPointer	t_classFuncs[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string		t_classFuncIndex[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	index = 0;
	while (index < 4 && t_classFuncIndex[index].compare(level))
		index++;
	if (index < 4)
		(this->*t_classFuncs[index])();
}