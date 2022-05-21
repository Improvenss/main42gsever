/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:42:43 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	unsigned int		j;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (dest[i] && i < size)
		i++;
	j = i;
	while (src[j - i] && j < size - 1)
	{
		dest[j] = src[j - i];
		j++;
	}
	if (j > i)
		dest[j] = '\0';
	return (i + ft_strlen(src));
}
