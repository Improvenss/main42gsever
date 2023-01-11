/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:50:53 by gsever            #+#    #+#             */
/*   Updated: 2023/01/03 17:51:55 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl		hey;
	std::string	level;

	while (1)
	{
		std::cout << "Write level: DEBUG, INFO, WARNING, ERROR, EXIT(For finish program)" << std::flush << std::endl;
		std::cout << "$୯> " << std::flush;
		std::getline(std::cin, level);
		if (!level.compare("EXIT"))
			return (0);
		else if (!level.compare("DEBUG") || !level.compare("INFO") || !level.compare("WARNING") || !level.compare("ERROR"))
			hey.complain(level);
		else
			std::cout << "Wrong level choise, try again." << std::flush << std::endl;
	}
	return (0);
}