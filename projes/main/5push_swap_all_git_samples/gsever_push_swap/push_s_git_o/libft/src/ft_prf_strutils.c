/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_strutils.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:42:49 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 18:35:05 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_prf_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	if (!(str = (char *)ft_prf_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

size_t		ft_prf_strlen(const char *str)
{
	size_t len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char		*ft_prf_strncpy(char *dest, char *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char		*ft_prf_strsub(char const *s, unsigned int start, size_t len)
{
	char	*so;

	if (!(so = ft_prf_strnew(len)) || !s)
		return (NULL);
	so = ft_prf_strncpy(so, (char *)s + start, len);
	return (so);
}

int			contains(char *str, char c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}
