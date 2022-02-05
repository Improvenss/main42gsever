/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:37:41 by gsever            #+#    #+#             */
/*   Updated: 2022/02/05 16:46:11 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//belirli bir string icerisindeki starttan itibaren len kadarki kismi aliyor.
//(int start) >= (s = "gorkem")
//gorkem --> kem
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