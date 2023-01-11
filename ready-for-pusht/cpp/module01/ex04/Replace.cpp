/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:28:31 by gsever            #+#    #+#             */
/*   Updated: 2023/01/03 15:26:35 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

std::string	replaceInput(std::string readedline, std::string s1, std::string s2)
{
	std::string	okLine;
	int	readedLineLenght;
	int	s1Len;
	int	s2Len;
	int	start;

	readedLineLenght = readedline.length();//satir uzunlugu
	s1Len = s1.length();//s1 uzunlugu
	s2Len = s2.length();//s2 uzunlugu
	start = 0;//satirimizin icindeki index.
	std::cout << "s1:" << s1 << "|s2:" << s2 << "|" << readedline << "|" << std::flush << std::endl;
	while (start < readedLineLenght)
	{
		if (!readedline.compare(start, s1Len, s1))// readedLine icinde baslangic indexinden itibaren s1'in uzunlugu kadar karsilastira karsilastira ilerliyoruz.
		{//match inside line this s1
			okLine += s2;
			start += s1Len;
		}
		else
		{
			okLine += readedline[start];
			start++;
		}
	}
	return (okLine);
}//hello gorkem
 //hello balonkem