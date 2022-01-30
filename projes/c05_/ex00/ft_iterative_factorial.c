/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 02:40:24 by gsever            #+#    #+#             */
/*   Updated: 2021/12/12 03:45:00 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_calculate(int value)
{
	unsigned int	result;

	result = 1;
	while (value > 0)
	{
		result = result * value;
		value--;
	}
	return (result);
}

int	ft_iterative_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	else
		return (ft_calculate(nb));
}
/*
int	main(void)
{
	printf("%d", ft_iterative_factorial(100));
}
*/
