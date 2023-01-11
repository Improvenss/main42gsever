/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:24:12 by gsever            #+#    #+#             */
/*   Updated: 2023/01/11 12:41:30 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * @brief 
 * 
 * "&" will find its location,
 * "*" will find what value's there.
 * @return int 
 */
int	main()
{
	std::string	brain = "HI THIS IS BRAIN";// kendisi
	std::string	*stringPTR = &brain;// adresini turuyor = adresini atiyoruz
	std::string	&stringREF = brain;// referansini aliyor. Yani stringREF = brain gibi :D

	//&str : str
	// stringPTR : *stringPTR
	// &stringREF : stringREF
	std::cout << "___________MEMORY ADDRESS__________" << std::flush << std::endl;
	std::cout << "&String-> " << &brain << std::flush << std::endl;
	std::cout << "stringPTR-> " << stringPTR << std::flush << std::endl;
	std::cout << "&stringREF-> " << &stringREF<< std::flush << std::endl;
	std::cout << "___________POINTER VALUE___________" << std::flush << std::endl;
	std::cout << "String-> " << brain << std::flush << std::endl;
	std::cout << "*stringPTR-> " << *stringPTR << std::flush << std::endl;
	std::cout << "stringREF-> " << stringREF << std::flush << std::endl;
	return (0);
}