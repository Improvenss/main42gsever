/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils3.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:06:42 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 13:32:18 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void		reorder_pile(t_piles **piles)
{
	int		dir;
	t_piles	*tmp;

	tmp = *piles;
	dir = get_min_index(tmp) > (tmp->a_len / 2);
	while (get_min_index(tmp) != 0)
		tmp = launch_cmd(tmp, dir ? "rra" : "ra");
}

int			real_index(t_piles *pile, int index)
{
	if (index >= pile->a_len)
		return (index - pile->a_len);
	else if (index < 0)
		return (pile->a_len - 1);
	return (index);
}

int			get_min_index(t_piles *piles)
{
	int		i;
	int		imin;

	i = 1;
	imin = 0;
	while (i < piles->a_len)
	{
		if (piles->index_a[i] == 0)
			imin = i;
		i++;
	}
	return (imin);
}

t_piles		*launch_cmd(t_piles *pile, char *cmd)
{
	if (cmd)
		pile->next = fill_piles(pile, &cmd);
	else
		pile->next = NULL;
	return (exec_cmd(pile));
}
