/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:04:50 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/14 16:45:04 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iterative_factorial(int nb)
{
	int	fact_nb;

	if (nb < 0 || nb > 12)
		return (0);
	fact_nb = 1;
	while (nb > 0)
	{
		fact_nb *= nb;
		nb--;
	}
	return (fact_nb);
}
