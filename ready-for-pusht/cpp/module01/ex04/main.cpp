/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:24:14 by gsever            #+#    #+#             */
/*   Updated: 2023/01/11 13:24:19 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream	readFile;// For reading file.
		std::ofstream	writeFile;// For writing file.
		std::string		readedLine;
		std::string		tmpReadFile = argv[1];

		readFile.open(argv[1]);// This file must be same location.
		if (!readFile.is_open())
		{
			std::cout << argv[1] << " can't open!" << std::flush << std::endl;
			return (1);
		}
		// writeFile.open(tmpReadFile.append(".replace"));// File creating for write.
		writeFile.open(tmpReadFile + ".replace");// File creating for write.
		if (writeFile.is_open())
		{
			while (std::getline(readFile, readedLine))
			{
				readedLine = replaceInput(readedLine, argv[2], argv[3]);
				writeFile << readedLine << std::flush << std::endl;
			}
		}
		else
			std::cout << "Write file can't open!" << std::flush << std::endl;
		readFile.close();
		writeFile.close();
	}
	else
		std::cout << "You must be enter: ./replace <filename> <s1> <s2>" << std::flush << std::endl;
	return (0);
}