/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:34:59 by gsever            #+#    #+#             */
/*   Updated: 2022/12/03 01:50:59 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Always returning (ERROR(-1)).
 * 
 * @param s1 
 * @param s2 
 * @param s3 
 * @param message 
 * @return int ERROR: -1
 */
int	print_error(char *s1 __attribute((unused))
	, char *s2 __attribute((unused))
	, char *s3 __attribute((unused))
	, char *message __attribute((unused)))
{
	if (s1)
		ft_putstr_fd(s1, 2);
	if (s2)
	{
		if (s1)
			ft_putstr_fd(": ", 2);
		ft_putstr_fd(s2, 2);
	}
	if (s3)
	{
		if (s1 || s2)
			ft_putstr_fd(": ", 2);
		ft_putstr_fd(s3, 2);
	}
	if (message)
	{
		if (s1 || s2 || s3)
			ft_putstr_fd(": ", 2);
		ft_putstr_fd(message, 2);
	}
	ft_putstr_fd(B_RED"\nError\n"END, 2);
	return (ERROR);
}

/**
 * @brief Printing errno.h's errno string value.
 * 
 * Updates error.h's inside errno=0 in case of
 *  any system func()'s error.
 * 
 * @param s1 
 * @param s2 
 * @param s3 
 * @return int 
 */
int	print_error_errno(char *s1, char *s2, char *s3)
{
	print_error(s1, s2, s3, strerror(errno));
	errno = 0;
	return (ERROR);
}
