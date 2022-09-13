/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:34:58 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:16 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//Adds the node ’new’ at the end of the list.
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
void print_all_ls(t_list *start)
{
	t_list *temp = start;
	while(temp->next != NULL)
	{	
		printf("ft_:%s\n", temp->content);
		temp = temp->next;
	}
	printf("ft_:%s\n", temp->content);
}

int	main()
{
	t_list *lst = ft_lstnew("start");
	t_list *gorkem = ft_lstnew("gorkem");
	t_list *sever = ft_lstnew("sever");

	ft_lstadd_back(&lst, gorkem);
	ft_lstadd_back(&gorkem, sever);

	print_all_ls(lst);	
}
*/