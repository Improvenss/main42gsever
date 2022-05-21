/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:56:43 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 14:56:45 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "limits.h"

int	cleanup(t_collection *stacks)
{
	delete_stack(stacks->a);
	delete_stack(stacks->b);
	free(stacks);
	return (0);
}

void	fatal_error(t_collection *stacks, const char *s)
{
	cleanup(stacks);
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

unsigned int	amount_digits(int n)
{
	unsigned int	digits;

	digits = 1;
	if (n < 0)
		digits = 1;
	while (n <= -10 || n >= 10)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

int	atoi_exit_on_error(const char *str, bool *error)
{
	int			sign;
	int			i;
	long int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (iswhitespace(str[i]))
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++str;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (10 * result) + (str[i] - '0');
		if (result < INT_MIN || result > INT_MAX)
			*error = true;
		++i;
	}
	return (sign * (int)result);
}

void	clearscreen(void)
{
	const ssize_t	dummy = write(STDOUT_FILENO, "\x1B[1;1H\x1B[2J", 11);

	(void)dummy;
}
