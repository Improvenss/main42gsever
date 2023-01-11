/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:33:35 by gsever            #+#    #+#             */
/*   Updated: 2023/01/03 13:14:53 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type)
{
	this->_type = type;
	std::cout << "Weapon address: " << &_type << std::endl;
}

Weapon::~Weapon( void )
{

}

const std::string	&Weapon::getType( void )
{
	return (this->_type);
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}