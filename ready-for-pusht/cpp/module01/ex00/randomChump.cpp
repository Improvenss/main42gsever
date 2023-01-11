/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:26:52 by gsever            #+#    #+#             */
/*   Updated: 2023/01/02 09:20:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Creating random zombie.
 * 
 * @param name 
 */
void	randomChump( std::string name )
{
	Zombie	randomZombie( name );
	randomZombie.announce();
}