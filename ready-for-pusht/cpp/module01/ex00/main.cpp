/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:05:35 by gsever            #+#    #+#             */
/*   Updated: 2023/01/11 12:04:47 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::string	zombieName;
	// int			choise;
	// std::string	input;
	// int			zombieIndex = -1;

	std::cout << "Welcome!" << std::flush << std::endl;
	std::cout << GREEN << "We are creating Zombie from Stack" << END << std::flush << std::endl;
	std::cout << "Enter Zombie name: " << std::flush;
	std::getline(std::cin, zombieName);
	Zombie	stackZombie(zombieName);
	stackZombie.announce();

	std::cout << GREEN << "We are creating Zombie from Heap" << END << std::flush << std::endl;
	std::cout << "Enter Zombie name: " << std::flush;
	std::getline(std::cin, zombieName);
	Zombie	*heapZombie = newZombie(zombieName);
	heapZombie->announce();
	delete	heapZombie;

	std::cout << "Creating randomChump(name)" << std::flush << std::endl;
	randomChump("randomZombie");
	// while (1);
	return (0);

	/*
	while (1)
	{
		// std::cout << "Enter your choise!" << std::flush << std::endl;
		std::cout << "Create a 'Zombie' for 'Heap': 2" << std::flush << std::endl;// After the program started, means new*, malloc(), free()...
		std::cout << "Create a 'Zombie' for 'Stack': 1" << std::flush << std::endl;// Inside the program starting area in memory.
		std::cout << "For exit the program: 0" << std::flush << std::endl;// Destrucor calling here, next step exit program.
		std::cout << "> " << std::flush;
		// std::cin >> choise;
		std::getline(std::cin, input);
		if (!input.compare("0"))
			return (1);
			// exit(0);
		else if (!input.compare("1"))
		{
			std::cout << GREEN << "We are creating Zombie from Stack" << END << std::flush << std::endl;
			std::cout << "Enter Zombie name: " << std::flush;
			std::getline(std::cin, zombieName);
			zombieIndex++;
			Zombie	stackZombie(zombieName + std::to_string(zombieIndex));
		}
		else if (!input.compare("2"))
		{
			std::cout << GREEN << "We are creating Zombie from Heap" << END << std::flush << std::endl;
			std::cout << "Enter Zombie name: " << std::flush;
			std::getline(std::cin, zombieName);
			zombieIndex++;
			// Zombie	stackZombie1(zombieName + std::to_string(zombieIndex));
			Zombie	*heapZombie = newZombie(zombieName + std::to_string(zombieIndex));
			heapZombie->announce();
		}
		else if (!input.compare("9"))
			destoryAllZombies();
		else
			std::cout << RED << "Wrong choise, try again!" << END << std::flush << std::endl;
	}
	*/
	// return (0);
}