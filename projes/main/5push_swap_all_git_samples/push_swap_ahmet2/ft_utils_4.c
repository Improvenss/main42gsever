/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:21:59 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/25 17:22:07 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_to_min_find_max(t_list **list_a, int min)
{
	t_list	*temp;
	int		data;

	temp = *list_a;
	data = temp->data;
	while (temp->data != min)
	{
		if (temp->data > data)
			data = temp->data;
		temp = temp->next;
	}
	return (data);
}

int	ft_onay_size(t_list *list_a, int min, int max)
{
	t_list	*temp;
	int		size;

	size = 0;
	temp = list_a;
	while (temp != NULL)
	{
		if (temp->data >= min && temp->data <= max)
			size++;
		temp = temp->next;
	}
	return (size);
}

int	ft_onay(t_list *list_a, int data, int min, int max)
{
	int		size;
	int		i;
	int		x;
	t_list	*temp;

	size = 0;
	i = 0;
	x = 0;
	size = ft_onay_size(list_a, min, max) / 2;
	temp = list_a;
	while (temp != NULL)
	{
		if (min >= temp->data)
			x++;
		if (data >= temp->data)
			i++;
		temp = temp->next;
	}
	if (size == i - x)
		return (1);
	else
		return (0);
}

int	ft_pivot_ara(t_list *list_a, int min, int max)
{
	t_list	*temp;
	int		onay;

	onay = 0;
	temp = list_a;
	while (temp != NULL)
	{
		onay = ft_onay(list_a, temp->data, min, max);
		if (onay == 1)
			return (temp->data);
		temp = temp->next;
	}
	return (temp->data);
}

void	ft_rrr_rra_rrb(t_list **list_a, t_list **list_b, int x, int y)
{
	if (x >= y)
	{
		x = x - y;
		while (y-- > 0)
			rrr(list_a, list_b);
		while (x-- > 0)
			rra(list_a);
	}
	else if (y > x)
	{
		y = y - x;
		while (x-- > 0)
			rrr(list_a, list_b);
		while (y-- > 0)
			rrb(list_b);
	}
}
