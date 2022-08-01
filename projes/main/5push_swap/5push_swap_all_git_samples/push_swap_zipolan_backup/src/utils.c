/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:54:33 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/25 18:46:15 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
	{
		if (s[count] != '\0')
			count++;
	}
	return (count);
}

int	is_digit(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '-')
		return (0);
	return (1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

size_t	length(char const *s, char c)
{
	size_t	len;
	size_t	amount;

	amount = 0;
	while (*s)
	{
		len = 0;
		while (*s != c && *s)
		{
			++len;
			++s;
		}
		if (len != 0)
		{
			++amount;
			--s;
		}
		++s;
	}
	return (amount);
}
