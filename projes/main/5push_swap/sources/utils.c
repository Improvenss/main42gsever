/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:22:15 by gsever            #+#    #+#             */
/*   Updated: 2022/06/28 13:56:54 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file	utils.c
 * @brief	Other auxiliary functions.
 * @author	Görkem SEVER (gsever)
 * @bug		Now know bugs.
 */
#include "../includes/push_swap.h"

/**
 * @brief	Counting arguman's numbers with space seperator(' ').
 * etc: ./push_swap "9 8 -3 2 -7 5"
 * 		--> seperator = ' '
 * 		--> str = "9 8 -3 2 -7 5"
 * @return	Number of counted numbers.
 * @bug		Not know bugs.
 */
size_t	arguman_length(const char *str, char c)
{
	size_t	len;
	size_t	amount;

	amount = 0;
	while (*str)
	{
		len = 0;
		while (*str != c && *str)
		{
			len++;
			str++;
		}
		if (len != 0)
		{
			amount++;
			str--;
		}
		str++;
	}
	return (amount);
}
