/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:34:24 by gsever            #+#    #+#             */
/*   Updated: 2023/01/03 13:20:36 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
// this->_name olarak kullanirsak adresi farkli oluyor, ondan dolayi & islemi gerceklesitirilemez.
}

HumanA::~HumanA( void )
{

}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::flush << std::endl;
	std::cout << "HumanA address: " << &this->_weapon.getType() << std::endl;
}