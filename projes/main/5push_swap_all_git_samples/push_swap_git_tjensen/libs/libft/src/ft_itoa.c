/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:05:19 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/04 13:07:46 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		numlen;
	long	nb;
	char	*n_str;

	nb = n;
	numlen = ft_get_numlen(nb);
	n_str = malloc((numlen + 1) * sizeof(char));
	if (n_str == NULL)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		n_str[i++] = '-';
		nb *= -1;
	}
	while (i < numlen)
	{
		n_str[i] = (nb / ft_iterative_power(10, numlen - i - 1)) % 10 + '0';
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
