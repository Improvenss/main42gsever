/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:09:00 by gsever            #+#    #+#             */
/*   Updated: 2022/06/27 22:13:28 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief	It's just writing string and start exit(1);
 * @return	1
 * @bug		Not know bugs.
 */
int	ft_error(char *str)
{
	ft_putstr_fd(*str, 1);
	exit (1);
	return (1);
}

/**
 * @brief	Just check if there are only numbers.
 * @return	void
 * @param	is_digit Scanning string, all argumans are digit.
 * @param	ft_error If have problem, writing "Error" and exit program.
 * @bug		Not know bugs.
 */
void	check_num(int ac, char **av)
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
				if ((!av[i][j + 1] >= '1' && av[i][j + 1] <= '9'))
					ft_error("Error\n");
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief	We are checking if the double quotation's output is correct or not.
 * @return	void
 * @param	arguman_length Counts numbers seperated by spaces in a string.
 * @param	is_digit Scanning string, all argumans are digit.
 * @param	ft_error If have problem, writing "Error" and exit program.
 * @bug		Not know bugs.
 */
void	check_num_double_quotation(char **av, t_base *base)
{
	int	i;

	i = 0;
	base->start.size = arguman_length(av, ' ');
	while (av[i])
	{
		if (is_digit(av[i]))
			ft_error("Error\n");
		if (av[i] == '-')
		{
			if (!(av[i + 1] >= '0' && av[i + 1] <= '9'))
				ft_error("Error\n");
		}
		i++;
	}
}
