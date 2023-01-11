/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:50:53 by gsever            #+#    #+#             */
/*   Updated: 2023/01/04 12:15:07 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl		hey;
		// std::cout << "Input: " << argv[1] << std::flush << std::endl;
		hey.complain(argv[1]);
	}
	else
		std::cout << "Too much arguman entered.\n ./harlFilter <just_this>" << std::flush << std::endl;
	return (0);
}