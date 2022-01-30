/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:42:42 by gsever            #+#    #+#             */
/*   Updated: 2021/12/08 02:26:55 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	main()
{
	printf("%d", ft_strcmp("0", "0\n"));//-10
	printf("\n%d", ft_strcmp("", "A"));//-65
	printf("\n%d", ft_strcmp("He", "Hello"));//-327
	printf("\n%d", ft_strcmp("Hello", "Hello"));
}
