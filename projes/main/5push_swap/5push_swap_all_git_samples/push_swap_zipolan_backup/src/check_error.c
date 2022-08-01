/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:56:06 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/27 11:11:29 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// verif si a est deja sort
void	is_sorted(t_base *base)
{
	int		i;

	i = 0;
	while (i + 1 < base->start.size)
	{
		if (base->a[i] < base->a[i + 1])
			++i;
		else
			return ;
	}
	ft_free(base);
}

// verif si un nombre se repete
void	is_repeated(t_base *base)
{
	int		i;
	int		j;

	i = 0;
	while (i < base->start.size)
	{
		j = i + 1;
		while (j < base->start.size)
		{
			if (base->a[i] == base->a[j])
				ft_error("Error\n");
			++j;
		}
		++i;
	}
}

int	ft_error(char *str)
{
	while (*str)
	{
		write(1, &(*str), 1);
		++str;
	}
	exit (1);
	return (1);
}

// verif si il n'y a que des nombres
void	check_num(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (is_digit(av[i][j]))
				ft_error("Error\n");
			if (av[i][j] == '-')
			{
				if (!(av[i][j + 1] >= '1' && av[i][j + 1] <= '9'))
					ft_error("Error\n");
			}
			++j;
		}
		++i;
	}
}

// verif si il n'y a que des nombres dans les quotes
void	check_num_q(char *av, t_base *base)
{
	int	i;

	i = 0;
	base->start.size = (int)length(av, ' ');
	while (av[i])
	{
		if (is_digit(av[i]))
			ft_error("Error\n");
		if (av[i] == '-')
		{
			if (!(av[i + 1] >= '0' && av[i + 1] <= '9'))
				ft_error("Error\n");
		}
		++i;
	}
}
