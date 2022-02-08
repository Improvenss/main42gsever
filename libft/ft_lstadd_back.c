/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:34:58 by gsever            #+#    #+#             */
/*   Updated: 2022/02/08 16:00:43 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
/*
int	main()
{
	t_list *gorkem = ft_lstnew("gorkem");
	t_list *sever = ft_lstnew("sever");
	ft_lstadd_back(&gorkem, sever);
		while (gorkem)
	{
		printf("lista: %s\n", gorkem->content);
		gorkem = gorkem->next;
	}
}
*/