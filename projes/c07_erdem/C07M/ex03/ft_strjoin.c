/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeskin <ekeskin@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:33:32 by ekeskin           #+#    #+#             */
/*   Updated: 2021/12/14 14:48:42 by ekeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		c;

	s = (char *)malloc(sizeof(strs));

	i = 0;
	c = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			s[c++] = strs[i][j++];
		}
		j = 0;
		while (sep[j] != '\0' && i != (size - 1))
		{
			s[c++] = sep[j++];
		}
		i++;
	}
	s[c] = '\0';
	return (s);
}

#include <stdio.h>

int	main(void)
{
	char *text[4];

	text[0] = "YAZI 1";
	text[1] = "YAZI 2";
	text[2] = "YAZI 3";
	text[3] = "YAZI 4";

	printf("%s\n", ft_strjoin(4, text, " - "));
}
