/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:38:32 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_revcpy(void *dst, void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	i = 0;
	ptrs = (unsigned char *)(src + n - 1);
	ptrd = (unsigned char *)(dst + n - 1);
	while (i < n)
	{
		*ptrd = (unsigned char)*ptrs;
		ptrd--;
		ptrs--;
		i++;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst >= src)
		ft_revcpy((void *)dst, (void *)src, len);
	else
		ft_memcpy((void *)dst, (void *)src, len);
	return (dst);
}
