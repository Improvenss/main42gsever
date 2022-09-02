/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:37:38 by gsever            #+#    #+#             */
/*   Updated: 2022/09/01 17:32:32 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_perror(char *str)
{
	printf("%s", str);
	exit(1);
}

void	wrong_args_error(void)
{
	printf(RED"ERROR:			-> ./philosophers ");
	printf("p_count die eat sleep [cycle count]\n"X);
	printf(RED"ERROR: Use like this	-> ./philosophers 7 800 200 200 5\n"X);
	printf(RED"Or			-> ./philosophers 7 800 200 200\n"X);
	ft_perror(RED"Wrong arguments!"X);
}
