/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:58:39 by gsever            #+#    #+#             */
/*   Updated: 2023/01/03 13:18:57 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	this->_name = name;
}

HumanB::~HumanB( void )
{

}

void	HumanB::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::flush << std::endl;
	std::cout << "HumanB address: " << &this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
}