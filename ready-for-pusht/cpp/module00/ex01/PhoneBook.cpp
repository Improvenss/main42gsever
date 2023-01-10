/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:43:22 by gsever            #+#    #+#             */
/*   Updated: 2023/01/10 13:43:56 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	// std::cout << "PhoneBook class's -Constructor-" << std::endl;
}

PhoneBook::~PhoneBook()
{
	// std::cout << "PhoneBook class's -Destructor-" << std::endl;
}

void	PhoneBook::exitProgram(void) const
{
	std::cout << "Program shutting down! See ya!" << std::endl;
	exit(0);
}

void	PhoneBook::addCommand(void)
{
	static int	userNumber;
	std::cout << "You are creating new user..." << std::endl;
	if (userNumber >= 8)
		userNumber = 0;
	std::cout << "User's number: " << userNumber << std::endl;
	this->_users[userNumber].setContact(userNumber);
	userNumber++;
}

/**
 * @brief Printing
 * 
 */
void	PhoneBook::searchCommand(void) const
{
	int			num;
	std::string	input;

	std::cout << "***** PHONE BOOK *****" << std::endl;
	for (int i = 0; i < 8; i++)
		this->_users[i].getContact();
	while (1)
	{
		std::cout << "Enter index num: ";
		std::getline(std::cin, input);
		// if (!strcmp(numStr, "EXIT"))
			// exit(0);
		num = atoi(input.c_str());
		std::cout << "Entered num: " << num << std::endl;
		if (std::cin.good()
			&& (input.length() == 1)
			&& ((num > 0 && num < 8)
			|| (input.compare("0") == 0 && num == 0)))
			break ;
		std::cin.clear();
		std::cout << "You must be enter between 0-7 value!" << std::endl;
	}
	this->_users[num].getUserInfo();
}
