/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:27:02 by gsever            #+#    #+#             */
/*   Updated: 2023/01/11 12:37:25 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie		*arrayZombies;
	std::string	nameOfZombies;
	int			numberOfZombies;

	std::cout << "Welcome!, we are creating Zombie array..." << std::flush << std::endl;
	std::cout << "Enter the number of Zombie to create: " << std::flush;
	// std::getline(std::cin, nameOfZombies);// Getting number of Zombie.
	// numberOfZombies = std::stoi(nameOfZombies);// Converting string to integer.
	// numberOfZombies = std::atoi(nameOfZombies.c_str());
	std::cin >> numberOfZombies;
	std::cout << "Zombie names: " << std::flush;
	// std::getline(std::cin, nameOfZombies);// Getting name of Zombies.
	std::cin >> nameOfZombies;
	arrayZombies = zombieHorde(numberOfZombies, nameOfZombies);// Creating N times Zombie to array.
	for (int i = 0; i < numberOfZombies; i++)
		arrayZombies[i].announce();
	delete [] arrayZombies;// Deleting Zombies of array.
	while (1);// for testing leaks.
	return (0);
}