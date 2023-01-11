/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:36:44 by gsever            #+#    #+#             */
/*   Updated: 2023/01/02 15:22:08 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*arrayZombie = new Zombie[N];

	for (int i = 0; i < N; i++)
		arrayZombie[i].setName(name + std::to_string(i));
	return (arrayZombie);
}