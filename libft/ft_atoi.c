/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:14:50 by gsever            #+#    #+#             */
/*   Updated: 2022/02/05 14:54:47 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"
//#include <stdio.h>
//static int = program calistirildiktan bitisine kadar saymaya devam eder.
static int	ft_isspace(char chr)
{
	if ((chr >= 9 && chr <= 13) || chr == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned long	ret_val;
	int				index;
	int				polarity;

	polarity = 1;
	index = 0;
	if (*nptr == '\0')
		return (0);
	while (ft_isspace(nptr[index]))
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			polarity *= -1;
		index++;
	}
	ret_val = 0;
	while (nptr[index] >= '0' && nptr[index] <= '9')
		ret_val = (ret_val * 10) + (nptr[index++] - '0');
	if (ret_val > LONG_MAX && polarity == -1)
		return (0);
	if (ret_val > LONG_MAX && polarity == 1)
		return (-1);
	return (ret_val * polarity);
}
/*
int main ()
{
    char *a;
    
    a = "-1234567";
    printf("ft_:%d", ft_atoi(a));
}
*/