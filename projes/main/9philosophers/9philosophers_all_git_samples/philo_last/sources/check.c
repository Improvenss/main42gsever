/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:07:34 by gsever            #+#    #+#             */
/*   Updated: 2022/09/02 12:38:38 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

/** --> OK
 * @brief Checking base struct's values.
 * 
 * -> Do not test with more than 200 philosophers.
 * -> Do not test with time_to_die or time_to_eat or
 * 	time_to_sleep set to values lower than 60 ms.
 * 
 * @return void
 * @param base Base structure.
 * @fn ft_perror	: If have error writing terminal "STR" and exit(-1).
 */
void	check_args_values(t_base *base)
{
	if (base->number_of_philo > 200)
		ft_perror(RED"ERROR: Philosophers count can't more than 200!"X);
	else if (base->time_to_die < 60 || base->time_to_eat < 60
		|| base->time_to_sleep < 60)
		ft_perror(RED"ERROR: time_to_die/eat/sleep \
values can't be lower than 60 ms."X);
}

/** --> OK
 * @brief ARGS sayimiz dogruysa bu func() calisacak. 
 * @return void
 * @param ac
 * @param av**
 * @fn ft_perror	: If have error writing terminal "STR" and exit(-1).
 * @bug Clear.
 */
void	check_args_on_shell(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '\0')
			ft_perror(RED"ERROR: Arguman can't be NULL!"X);
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				ft_perror(RED"ERROR: Arguman need just numbers."X);
			j++;
		}
		i++;
	}
}

/** --> OK
 * @brief 5 ya da 6 oldugunda calisacak yoksa error.
 * 
 * -> Programların alacağı argümanlar;
 * 		(1)Filozof Sayısı, (2)Ölme Süresi, (3)Yemek Yeme Süresi,
 * 		(4)Uyuma Süresi, (5)Her Filozofun Yemek Yeme Sayısı.
 * 
 * @return void
 * 
 * @param argc
 * @param argv
 * 
 * @fn check_args_on_shell : Checking args are ture format.
 * @fn printf : For error str writing.
 * @fn ft_perror : If have error writing terminal "STR" and exit(-1).
 * 
 * @bug Clear.
 */
void	check_args(int ac, char **av)
{
	if (ac == 5 || ac == 6)
		check_args_on_shell(ac, av);
	else
	{
		printf(RED"ERROR:			-> ./philosophers ");
		printf("p_count die eat sleep [cycle count]\n"X);
		printf(RED"ERROR: Use like this	-> ./philosophers 7 800 200 200 5\n"X);
		printf(RED"Or			-> ./philosophers 7 800 200 200\n"X);
		ft_perror(RED"Wrong arguments!"X);
	}
}
