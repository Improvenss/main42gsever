/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:14:45 by gsever            #+#    #+#             */
/*   Updated: 2022/07/27 00:51:39 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_isspace(char chr)
{
	if ((chr >= 9 && chr <= 13) || chr == ' ')
		return (1);
	return (0);
}

bool	ft_if_args_mintm(const char *argv)
{
	long	ret_value;
	int		i;
	int		polarity;

	i = 0;
	polarity = 1;
	while (ft_isspace(argv[i]))
		i++;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			polarity *= -1;
		i++;
	}
	ret_value = 0;
	while (argv[i] >= '0' && argv[i] <= '9')
		ret_value = (ret_value * 10) + (argv[i++] - '0');
	ret_value *= polarity;
	if (ret_value > INT_MAX || ret_value < INT_MIN)
		return (true);
	else
		return (false);
}
