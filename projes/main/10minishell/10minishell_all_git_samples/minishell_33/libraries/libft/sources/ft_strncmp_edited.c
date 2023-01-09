/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_edited.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 03:04:25 by gsever            #+#    #+#             */
/*   Updated: 2022/09/23 16:00:29 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strncmp_edited.c
 * @author Görkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/libft.h"

/**
 * @brief Ahmet's edited code.
 * 
 * @note Line(46) "(s1[n] == ' ' || s1[n] == '\0')" cd .. <enter> durumu,
 * 	cd.. <enter> şeklinde kullanılmasını engellemek için konuldu.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int	ft_strncmp_edited(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1 && (*s1 != '\0') && (*s1 == *s2) && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0 && (s1[n] == ' ' || s1[n] == '\0'))
		return (1);
	return (0);
}
