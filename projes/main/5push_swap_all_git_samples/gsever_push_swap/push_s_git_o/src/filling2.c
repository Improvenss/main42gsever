/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filling2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 17:51:09 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 17:51:09 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		increment_tot(t_piles *piles, char *str, int j, int tot)
{
	if ((str[j] && ((ft_isdigit(str[j])) || (str[j] == '-'))))
	{
		piles->pile_a[tot] = ft_atoi_secure(str + j);
		tot++;
	}
	return (tot);
}

int		avtoi(t_piles *piles, int ac, char **av)
{
	int			i;
	int			j;
	int			tot;

	i = 1;
	tot = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] && av[i][j] == ' ')
				j++;
			tot = increment_tot(piles, av[i], j, tot);
			j += av[i][j] == '-' ? 1 : 0;
			while ((av[i][j] && ((ft_isdigit(av[i][j])))))
			{
				if (!ft_isdigit(av[i][j]))
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}
