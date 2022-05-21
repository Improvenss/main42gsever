/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmds.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: uman <uman@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 16:14:12 by uman         #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 18:56:56 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void		exec_s(t_piles *pile)
{
	t_piles		*first;

	first = pile;
	dup_piles(pile->next, pile);
	pile = pile->next;
	if (first->cmd[1] == 'a' || first->cmd[1] == 's')
	{
		bit_swapper(pile->pile_a, 0, 1);
		bit_swapper(pile->index_a, 0, 1);
	}
	if (first->cmd[1] == 'b' || first->cmd[1] == 's')
	{
		bit_swapper(pile->pile_b, 0, 1);
		bit_swapper(pile->index_b, 0, 1);
	}
}

void		exec_r(t_piles *pile, int rev)
{
	t_piles			*first;
	unsigned int	cmdlen;

	cmdlen = ft_strlen(pile->cmd);
	first = pile;
	dup_piles(pile->next, pile);
	pile = pile->next;
	if (first->cmd[cmdlen - 1] == 'a' || first->cmd[cmdlen - 1] == 'r')
		rotate_pile(pile, 0, rev);
	if (first->cmd[cmdlen - 1] == 'b' || first->cmd[cmdlen - 1] == 'r')
		rotate_pile(pile, 1, rev);
}

void		exec_p(t_piles *pile)
{
	t_piles		*first;

	first = pile;
	dup_piles(pile->next, pile);
	pile = pile->next;
	if (pile->b_len > 0 && first->cmd[1] == 'a')
	{
		pile->a_len++;
		rotate_pile(pile, 0, 1);
		(pile->pile_a)[0] = (pile->pile_b)[0];
		(pile->index_a)[0] = (pile->index_b)[0];
		rotate_pile(pile, 1, 0);
		pile->b_len--;
	}
	if (pile->a_len > 0 && first->cmd[1] == 'b')
	{
		pile->b_len++;
		rotate_pile(pile, 1, 1);
		(pile->pile_b)[0] = (pile->pile_a)[0];
		(pile->index_b)[0] = (pile->index_a)[0];
		rotate_pile(pile, 0, 0);
		pile->a_len--;
	}
}

t_piles		*exec_cmd(t_piles *pile)
{
	if (pile->cmd == NULL)
		return (NULL);
	if ((pile->cmd)[0] == 's')
		exec_s(pile);
	else if ((pile->cmd)[0] == 'p')
		exec_p(pile);
	else if ((pile->cmd)[0] == 'r')
		exec_r(pile, ft_strlen(pile->cmd) > 2);
	return (pile->next);
}

int			launch_sort(t_piles *pilelst)
{
	t_piles		*pstart;

	pstart = pilelst;
	while (pilelst)
		pilelst = exec_cmd(pilelst);
	return (check_pile(pstart, 1));
}
