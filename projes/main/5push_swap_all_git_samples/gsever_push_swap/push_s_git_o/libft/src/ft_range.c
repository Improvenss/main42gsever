/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 10:20:01 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:32:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int *res;
	int j;

	if (min >= max)
		return (0);
	else
	{
		res = (int*)malloc(sizeof(int) * (max - min));
		if (res == NULL)
			return (0);
		i = min;
		j = 0;
		while (i < max)
		{
			res[j] = i;
			j++;
			i++;
		}
	}
	return (res);
}
