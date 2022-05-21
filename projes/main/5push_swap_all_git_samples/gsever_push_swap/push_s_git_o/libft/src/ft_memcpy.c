/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:38:14 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	i = 0;
	ptrs = (unsigned char *)src;
	ptrd = (unsigned char *)dst;
	while (i < n)
	{
		*ptrd = (unsigned char)*ptrs;
		ptrd++;
		ptrs++;
		i++;
	}
	return (dst);
}
