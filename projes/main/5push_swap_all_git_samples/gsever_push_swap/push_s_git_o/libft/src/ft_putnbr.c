/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:40:32 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tenpower_1(int n)
{
	int res;
	int iter;

	iter = 0;
	res = 1;
	while (iter < n)
	{
		res = res * 10;
		iter++;
	}
	return (res);
}

static int	ft_getpositive(int n)
{
	unsigned int un;

	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
			un = 2147483648;
		else
			un = -n;
	}
	else
		un = n;
	return (un);
}

void		ft_putnbr(int n)
{
	int						size;
	int						isize;
	unsigned int			npart;
	unsigned int			deci;

	n = ft_getpositive(n);
	npart = n;
	size = 0;
	while (npart > 9)
	{
		size++;
		npart = npart / 10;
	}
	isize = 0;
	npart = n;
	while (isize < size)
	{
		deci = npart / ft_tenpower_1(size - isize);
		ft_putchar('0' + deci);
		npart = npart - deci * ft_tenpower_1(size - isize);
		isize++;
	}
	ft_putchar('0' + npart);
}
