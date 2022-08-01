/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:35:34 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:34 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//doing same thing as lstiter.c + 'del' function used to if needed. ingye gel :'
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;

	if (lst == NULL || f == NULL)
		return (NULL);
	begin = 0;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, new);
		lst = lst->next;
	}
	return (begin);
}
/*
void	*ft_map(void *ct)
{
	int i = -1;
	char	*pouet;

	pouet = strdup((char *)ct);
	while (pouet[++i]!='\0')
		if (pouet[i] == 's')
			pouet[i] = 'o';
	return ((void *)pouet);
}
void ft_del(void *content)
{	
	//bzero(content, sizeof(content));
	memset(content, 0, strlen(content));
}

int	main()
{	
	char l[] = "start";
	char s0[] = "student0";
	char s1[] = "student1";
	char s2[] = "student2";

	t_list *lst = ft_lstnew(l);
	t_list *student0 = ft_lstnew(s0);
	t_list *student1 = ft_lstnew(s1);
	t_list *student2 = ft_lstnew(s2);
	
	ft_lstadd_back(&lst, student0);
	ft_lstadd_back(&lst, student1);
	ft_lstadd_back(&lst, student2);

	t_list *newlist = ft_lstmap(lst, ft_map, ft_del);
	while(lst)
	{
		puts((char *)lst->content);
		lst = lst->next;
	}

	while(newlist)
	{
		puts((char *)newlist->content);
		newlist = newlist->next;
	}
}
*/