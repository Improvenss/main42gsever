/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:35:05 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:19 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
linked list yani bagli liste dinamik boyutludur istedigi zaman artar.
-veri yapilari yani data structures-
olusturdugumuz listeyi listenin basina atar.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst && !new)
		return ;
	new->next = *lst;
	*lst = new;
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
// student2 -> student1 -> student0 -> lst
int	main()
{
	t_list *lst = ft_lstnew("start");
	t_list *student0 = ft_lstnew("student0");
	t_list *student1 = ft_lstnew("student1");
	t_list *student2 = ft_lstnew("student2");


	ft_lstadd_front(&lst, student0);
	ft_lstadd_front(&lst, student1);
	ft_lstadd_front(&lst, student2);

	print_all_ls(lst);
}
*/