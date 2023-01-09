/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:35:23 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:25 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*
lst aliyor, del() fonksiyonuyla lst'nin memorydeki yerini siler. next'in
memorydeki yeri temizlenmis olmamalidir.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
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

	ft_lstdelone(student1, ft_del);
	while(lst)
	{
		puts((char *)lst->content);
		lst = lst->next;
	}
}
*/