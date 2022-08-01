/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:46:10 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/14 11:23:22 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(long n)
{
	int		i;
	int		numlen;
	u_long	num;
	char	*n_str;

	numlen = ft_get_numlen(n);
	n_str = malloc((numlen + 1) * sizeof(char));
	if (n_str == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
		n_str[i++] = '-';
	num = ft_abs(n);
	while (i < numlen)
	{
		n_str[i] = (num / ft_iterative_power(10, numlen - i - 1)) % 10 + '0';
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
