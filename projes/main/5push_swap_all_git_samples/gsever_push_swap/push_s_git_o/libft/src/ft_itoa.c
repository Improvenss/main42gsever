/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:36:46 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	res_len(int value)
{
	int				len;
	unsigned int	nb;

	len = 0;
	if (value < 0)
	{
		nb = -value;
		len++;
	}
	else
		nb = value;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	if (value == 0)
		len = 1;
	return (len);
}

char		*ft_itoa(int value)
{
	char			*str;
	int				len;
	int				i;
	unsigned int	nb;

	nb = value;
	len = res_len(value);
	i = 0;
	if (value < 0)
		nb = -value;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (value < 0)
		str[0] = '-';
	else
		str[0] = '0';
	while (i < len - (value < 0))
	{
		str[len - i - 1] = '0' + nb % 10;
		nb /= 10;
		i++;
	}
	str[len] = 0;
	return (str);
}
