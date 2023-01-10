/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:37:36 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:18:46 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
set'teki string'i s1'in basindan ve sonundan siliyor
not: ABgorkeABmAB'de A yi cikartmak istedigimizde, xBgorkeABmAB oluyor. x ile
isaretledigim A cikartiliyor. Kenarinda A yok AB var, B'den sonra geliyor A,
o yuzden icine girmis oluyor ve cikartmiyore. :)
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*ret;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *((char *)s1)))
		s1++;
	start = (char *)s1;
	while (*s1)
		s1++;
	while (ft_strchr(set, *((char *)s1)) && s1 >= start)
		s1--;
	s1++;
	ret = malloc(sizeof(char) * (s1 - start + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, start, s1 - start + 1);
	return (ret);
}
/*
int	main()
{
	char a[] = "ABgorkeABmAB";
	char b[] = "AB";

	printf("ft_:%s\n", ft_strtrim(a, b));
}
*/