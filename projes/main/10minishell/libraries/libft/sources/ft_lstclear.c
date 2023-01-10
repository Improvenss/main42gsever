/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:35:10 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:21 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
'del' ve free(3) kullanarak elemani siler ve hafizadaki yerini temizler.
Silme islemi sonucunda hedefteki gonderdigin yer dahil olmak uzere devamini
da siler.
Yani list -> student0 ->(gonderdin) student1 [deleted]-> student2 [deleted]
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ptr;
	}
	*lst = NULL;
}
/*
void ft_del(void *content)
{
	//memset(content, 0, strlen(content));
	bzero(content, sizeof(content));
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

	ft_lstclear(&lst, ft_del);
	while(lst)
	{
		puts((char *)lst->content);
		lst = lst->next;
	}
}
*/