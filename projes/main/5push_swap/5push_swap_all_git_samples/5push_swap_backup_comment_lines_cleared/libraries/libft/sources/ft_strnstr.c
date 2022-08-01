/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:32:48 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:18:40 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
samanlikta igne aramak. "gorkem sever" "ke" ariyorsun
buldugunda direkt k'den itibaren yazdiriyorsun.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	counter;
	unsigned int	len_needle;

	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *) haystack);
	if (len == 0)
		return ((char *) NULL);
	counter = 0;
	while (counter <= (len - len_needle) && haystack[counter] != '\0')
	{
		if (ft_strncmp(&haystack[counter], needle, len_needle) == 0)
			return ((char *)&haystack[counter]);
		counter++;
	}
	return ((char *) NULL);
}
/*
#include <stdio.h>
int main()
{
    char *a;
    char *b;
    
    a = "gorkem sever";
    b = "ke";
    printf("ft_:%s", ft_strnstr(a, b, 5));
}
*/	