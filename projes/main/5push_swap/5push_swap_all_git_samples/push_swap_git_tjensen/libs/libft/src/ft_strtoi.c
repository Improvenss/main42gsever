/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:28:20 by tjensen           #+#    #+#             */
/*   Updated: 2021/10/05 14:55:51 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_base(char *base);
static int	isspace_and_sign(char *str, int *sign);

/*
** Simple function to convert a string input to a number.
** The bytes define how many bytes should be converted (int, long, etc.)
**
** RETURN VALUES:
** 0: the conversion was successful
** -1: the base check failed, so its not valid
** -2: the conversion is effected by an overflow
*/
int	ft_strtoi(char *str, int *num, char *base)
{
	int		i;
	int		sign;
	size_t	base_count;
	int		return_value;
	long	l_num;

	l_num = 0;
	return_value = 0;
	base_count = ft_check_base(base);
	if (base_count == 0)
		return (-1);
	i = isspace_and_sign(str, &sign);
	while (str[i] && ft_strchr(base, str[i]))
	{
		l_num *= base_count;
		l_num += (ft_strchr(base, str[i]) - base);
		i++;
		if (l_num > 2147483648 || (l_num == 2147483648 && sign == 1))
			return_value = -2;
	}
	*num = sign * l_num;
	return (return_value);
}

static int	ft_check_base(char *base)
{
	int		i;
	int		j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || !ft_isprint(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int	isspace_and_sign(char *str, int *sign)
{
	int	i;

	*sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		*sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (i);
}
