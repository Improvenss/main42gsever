/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:42:49 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 17:48:49 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		*ptr = (unsigned char)c;
		ptr++;
		i++;
	}
	return (b);
}

static void		ft_bzero(void *s, size_t len)
{
	ft_memset(s, 0, len);
}

void			*ft_prf_memalloc(size_t len)
{
	void	*mem;

	if (!(mem = (void *)malloc(len)))
		return (NULL);
	ft_bzero(mem, len);
	return (mem);
}

int				max(int a, int b)
{
	return (a > b ? a : b);
}

int				putnchar(const int nb, const char c)
{
	char	str[nb + 1];
	int		i;

	if (nb <= 0)
		return (0);
	i = 0;
	while (i < nb)
		str[i++] = c;
	str[nb] = 0;
	write(1, str, nb);
	return (nb);
}
