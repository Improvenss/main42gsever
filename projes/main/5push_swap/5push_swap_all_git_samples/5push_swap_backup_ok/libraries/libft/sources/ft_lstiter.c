/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:35:17 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:28 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//iterates the list 'lst' and applies the function on the content of each node.
//Listenin üzerinde dolanır ve 'f' listenin her elemaninin içeriğine uygular.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f == NULL)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void ft_del(void *content)
{	
	//bzero(content, sizeof(content));
	memset(content, 'R', strlen(content));
}
//not: ft_lstitter(burada * kullanmadik)
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

	ft_lstiter(lst, ft_del);
	while(lst)
	{
		puts((char *)lst->content);
		lst = lst->next;
	}
}
*/