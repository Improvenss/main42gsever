/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:54:47 by gsever            #+#    #+#             */
/*   Updated: 2022/09/05 20:55:06 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief Write "string" terminal
 * @return 1
 * @bug Clear.
 */
int	ft_perror_b(char *str)
{
	printf("%s\n", str);
	exit(-1);
	return (1);
}
