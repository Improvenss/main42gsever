/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:56:06 by bbourcy           #+#    #+#             */
/*   Updated: 2022/06/28 12:23:09 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// remplir la stack
void	stack_fill(char **av, int ac, t_base *base)
{
	int		n;
	int		i;

	n = 1;
	i = 0;
	while (n <= base->start.size)
	{
		if (av[n][0] == '-')
		{
			av[n][0] = '+';
			base->a[i] = ft_atoi(av[n], base);
			base->a[i] *= -1;
		}
		else if (av[n][0] == '0')
			base->a[i] = 0;
		else
			base->a[i] = ft_atoi(av[n], base);
		n++;
		if (n < ac)
			i++;
	}
}

// remplir la stack avec quotes
void	stack_fill_q(char **av, t_base *base)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (n < base->start.size)
	{
		if (av[n][0] == '-')
		{
			av[n][0] = '+';
			base->a[i] = ft_atoi(av[n], base);
			base->a[i] *= -1;
		}
		else if (av[n][0] == '0')
			base->a[i] = 0;
		else
			base->a[i] = ft_atoi(av[n], base);
		n++;
		if (n < base->start.size)
			i++;
	}
}

// verifier les arguments
void	arg_checker(int argc, char **argv, t_base *base)
{
	if (argc > 2)
	{
		base->start.size = argc - 1;
		check_num(argv, argc);
		return ;
	}
	else if (argc == 2)
	{
		check_num_q(argv[1], base);
	}
}

void	kill_prog(char *str, t_base *base)
{
	while (*str)
	{
		write(1, &(*str), 1);
		++str;
	}
	ft_free(base);
}

int	ft_atoi(const char *str, t_base *base)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if (num < 0)
		kill_prog("Error\n", base);
	return (num * neg);
}
