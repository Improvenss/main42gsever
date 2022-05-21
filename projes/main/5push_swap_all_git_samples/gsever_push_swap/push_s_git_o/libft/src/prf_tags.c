/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prf_tags.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 20:09:57 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 11:11:26 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			getprct(char *str, int p)
{
	while (str[p] && str[p] != '%')
		p++;
	return (p);
}

char		istag(char c)
{
	return (c == 's' ||
			c == '%' ||
			c == 'x' ||
			c == 'X' ||
			c == 'd' ||
			c == 'D' ||
			c == 'i' ||
			c == 'u' ||
			c == 'U' ||
			c == 'o' ||
			c == 'O' ||
			c == 'c' ||
			c == 'C' ||
			c == 'p'
			? c : 0);
}

char		isflag(char c)
{
	return (c == '+' ||
			c == '-' ||
			c == '0' ||
			c == '#' ||
			c == ' '
			? c : 0);
}

char		isopt(char c)
{
	return ((c <= '9' && c >= '0') ||
			c == '.' ||
			c == '#' ||
			c == 'l' ||
			c == 'j' ||
			c == '+' ||
			c == '-' ||
			c == 'z' ||
			c == ' ' ||
			c == 'h'
			? c : 0);
}

char		get_type(char *opt)
{
	int		i;

	i = 1;
	while (opt[i] && !istag(opt[i]) &&
			opt[i] != 'j' &&
			opt[i] != 'l' &&
			opt[i] != 'h' &&
			opt[i] != 'u' &&
			opt[i] != 'z')
		i++;
	if (!opt[i] || istag(opt[i]))
		return (0);
	if (opt[i] == 'l' && opt[i + 1] == 'l')
		return ('k');
	if (opt[i] == 'h' && opt[i + 1] == 'h')
		return ('i');
	else if (opt[i])
		return (opt[i]);
	return (0);
}
