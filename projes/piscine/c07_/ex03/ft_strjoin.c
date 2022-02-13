/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:52:54 by gsever            #+#    #+#             */
/*   Updated: 2021/12/14 18:00:17 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		bir;
	int		iki;
	int		c;
	
	s = malloc(sizeof(strs));
	if(!s)
		return 0;
	bir = 0;
	c = 0;
	while (bir < size)
	{
		iki = 0;
		while (strs[bir][iki] != '\0')
		{
			s[c++] = strs[bir][iki++];
		}
		iki = 0;
		while (sep[iki] != '\0' && bir != size - 1)
		{
			s[c++] = sep[iki++];
		}
		bir++;
	}
	s[c] = '\0';
	return (s);
}

#include<stdio.h>
int	main()
{

	char *a[] =  {"ali", "gorkem", "fatih"};
	printf("%s",ft_strjoin(3, a, "---"));
}
