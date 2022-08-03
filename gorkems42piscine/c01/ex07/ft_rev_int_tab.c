/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:51:24 by gsever            #+#    #+#             */
/*   Updated: 2022/08/04 02:43:50 by gsever           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	glass;

	i = 0;
	while (i < (size / 2))
	{
		glass = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = glass;
		i++;
	}
}
/*
#include <stdio.h>
int		main(void)
{
	int tab[20];
	int i;
	int size;

	size = 20;
	i = 0;
	while (i < size)
	{
		tab[i] = size - i;
		i++;
	}
	ft_rev_int_tab(tab, size);
	i = 0;
	while (i < size)
	{
		printf("%d: %d\n", i + 1, tab[i]);
		i++;
	}
}
*/
