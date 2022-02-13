/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:45:10 by gsever            #+#    #+#             */
/*   Updated: 2021/12/05 23:50:43 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	return (1);
	while(str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		i++;
		else
			return (0);
	}
	return (1);
}

int	main(void)
{
	printf("%d", ft_str_is_uppercase("hEFEFegg"));
}
