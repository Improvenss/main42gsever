/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:40:45 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tenpower_2(int n)
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

static int	ft_getpositive_fd(int n, int fd)
{
	unsigned int un;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
			un = 2147483648;
		else
			un = -n;
	}
	else
		un = n;
	return (un);
}

void		ft_putnbr_fd(int n, int fd)
{
	int						size;
	int						isize;
	unsigned int			npart;
	unsigned int			deci;

	n = ft_getpositive_fd(n, fd);
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
		deci = npart / ft_tenpower_2(size - isize);
		ft_putchar_fd('0' + deci, fd);
		npart = npart - deci * ft_tenpower_2(size - isize);
		isize++;
	}
	ft_putchar_fd('0' + npart, fd);
}
