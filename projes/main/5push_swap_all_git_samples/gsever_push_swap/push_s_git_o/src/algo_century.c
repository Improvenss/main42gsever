/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_century.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:47:04 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 18:53:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		algo_century(t_piles **pile)
{
	int		i;
	t_piles	*step;

	i = 0;
	step = *pile;
	while (i < (step->b_len + step->a_len + QS_THRESHOLD))
	{
		step = auto_split_a(step, i, i + QS_THRESHOLD);
		i += QS_THRESHOLD;
	}
	while (step->b_len > 0)
		step = pa_max(step);
}
