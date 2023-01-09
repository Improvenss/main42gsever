/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:36:58 by gsever            #+#    #+#             */
/*   Updated: 2022/10/13 17:52:37 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
s1 = "gorkem" | s2 = "sever" --> gorkemsever
2 stringi birlestiriyor.
not: static char -> sadece bu fonksiyon icinde kullanilabilinir. bu ft_strjoin.c
dosyasini baska dosyalarda kullanacagin zaman, ft_strcpy() diye cagiramazsin.
*/
static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (*src)
		dst[i++] = *((char *)src++);
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		ret_len;

	if (!s1 || !s2)
		return (NULL);
	ret_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(sizeof(char) * (ret_len));
	if (!ret)
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strlcat(ret, (char *)s2, ret_len);
	return (ret);
}
/*
int main()
{
	char a[] = "gorkem";
	char b[] = "sever";

	printf("ft_:%s", ft_strjoin(a, b));
}
*/