/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:47:53 by gsever            #+#    #+#             */
/*   Updated: 2021/12/14 01:16:40 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb > 0)
		result = nb * ft_recursive_factorial(nb - 1);
	if (nb < 0)
		return (0);
	return (result);
}
/*
int	main(void)
{
	printf("%i", ft_recursive_factorial(5));
}
*/
