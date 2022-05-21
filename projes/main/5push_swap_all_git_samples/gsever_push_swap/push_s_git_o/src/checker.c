/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: uman <uman@student.42.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 16:21:08 by uman         #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 18:40:45 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int			init_error(t_piles *piles)
{
	free_pilelst(piles);
	return (error());
}

int			main(int ac, char **av)
{
	char	*line;
	t_piles	*piles;
	t_piles	*pstart;

	piles = NULL;
	if (ac == 1)
		return (0);
	if (!init_piles(ac, av, &piles) || !check_dup(piles))
		return (init_error(piles));
	pstart = piles;
	while ((get_next_line(0, &line) == 1))
	{
		if (!iscmd(line))
		{
			ft_strdel(&line);
			free_pilelst(pstart);
			return (error());
		}
		piles = fill_piles(piles, &line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	launch_sort(pstart);
	free_pilelst(pstart);
	return (0);
}
