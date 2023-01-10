/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:02:20 by gsever            #+#    #+#             */
/*   Updated: 2022/12/30 13:08:50 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	pBook;
	std::string	input;

	std::cout << "Enter your command!\n ETC: ADD, SEARCH, EXIT" << std::endl;
	while (1)
	{
		std::cin.clear();
		std::cout << "$୯> ";
		// std::cin >> input;
		std::getline(std::cin, input);
		// std::cout << "inputun->[" << input << "]" << std::endl;
		if (std::cin.eof() || !input.compare("EXIT"))// std::cin.eof() -> ctrl+D/C/\ signals including here.
			pBook.exitProgram();
		else if (!input.compare("ADD"))
			pBook.addCommand();
		else if (!input.compare("SEARCH"))
			pBook.searchCommand();
		else
		{
			std::cout << "Wrong command sir!" << std::endl;
			std::cout << "You can enter just 'ADD', 'SEARCH', 'EXIT'" << std::endl;
		}
	}
	return (0);
}