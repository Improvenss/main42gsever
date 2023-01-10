/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:37:41 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:18:48 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
belirli bir string icerisindeki starttan itibaren len kadarki kismi aliyor.
(int start) >= (s = "gorkem") | len'i --> 3 | gorkem --> kem
not: 37.satirda len'imiz "gorkem[6]-->startimiz[2] yani 6-2=4" den buyukse
len'imizi string_len-start=len(4) yapiyoruz.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	src_len;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
	{
		ret = malloc(sizeof(char));
		if (!ret)
			return (NULL);
		*ret = '\0';
	}
	else
	{
		if ((src_len - start) < len)
			len = src_len - start;
		ret = malloc(sizeof(char) * len + 1);
		if (!ret)
			return (NULL);
		ft_strlcpy(ret, (char *)(s + start), len + 1);
	}
	return (ret);
}
/*
int main()
{
    char a[] = "gorkem";
    
	printf("ft_:%s\n", ft_substr(a, 3, 3));
}
*/