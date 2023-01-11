/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:10:23 by gsever            #+#    #+#             */
/*   Updated: 2023/01/02 09:21:20 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Construct a new Zombie:: Zombie object
 * 
 * Creating new Zombie in 'Stack'.
 * @param name 
 */
Zombie::Zombie( std::string name )
{
	this->_name = name;
}

/**
 * @brief Destroy the Zombie:: Zombie object
 * 
 * Destroying Zombies with 'delete' command.
 */
Zombie::~Zombie()
{
	std::cout << "Zombie " << RED << this->_name << END << " has been destroyed." << std::flush << std::endl;
}

/**
 * @brief Zombie's sayig own name.
 */
void	Zombie::announce( void )
{
	std::cout << CYAN << this->_name << END << ": BraiiiiiiinnnzzzZ..." << std::flush << std::endl;
}
