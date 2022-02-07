/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:37:07 by gsever            #+#    #+#             */
/*   Updated: 2022/02/07 17:53:19 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//copying up to size source -size-> destination (boyutu kadar kopyalama)
size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size > 0)
	{
		while (index < (size - 1) && src[index])
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	while (src[index])
		index++;
	return (index);
}
/* buraya bak daha bitmedi.
#include <string.h>
int	main ()
{
	char a[] ="gorkem";
	char b[] = "sever";
	char ft_a[] ="gorkem";
	char ft_b[] = "sever";

	printf("org:%zu\n", strlcpy(a, b, 4));
	printf("ft_:%zu\n", ft_strlcpy(ft_a, ft_b, 4));
}
*/