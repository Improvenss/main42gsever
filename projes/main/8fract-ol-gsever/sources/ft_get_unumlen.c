/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_unumlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:52 by gsever            #+#    #+#             */
/*   Updated: 2022/06/06 00:02:59 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	Counting line lengt. 
	Sample; Number = "1001001" --> lengt -> 7
		"[1]001001" --> count -> 1
		"1[0]01001" --> count -> 2
		"10[0]1001" --> count -> 3
		"100[1]001" --> count -> 4
		"1001[0]01" --> count -> 5
		"10010[0]1" --> count -> 6
		"100100[1]" --> count -> 7
*/
int	ft_get_unumlen(u_long nb)
{
	int	count;

	count = 1;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

/*
	It's counting line lengt but as much as entered.
	Sample; Number = "1001001" ---> Base = 100 --> lengt -> 4
		"[10]01001" --> count -> 1
		"10[01]001" --> count -> 2
		"1001[00]1" --> count -> 3
		"100100[1]" --> count -> 4
*/
int	ft_get_unumlen_base(u_long n, u_int base)
{
	int	numlen;

	numlen = 1;
	while (n / base)
	{
		numlen++;
		n /= base;
	}
	return (numlen);
}
