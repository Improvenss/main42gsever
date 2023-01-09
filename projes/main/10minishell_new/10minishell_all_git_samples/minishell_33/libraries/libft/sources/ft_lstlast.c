/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:35:28 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:32 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//listenin son elemanini return eder.
t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
/*
int	main()
{
	t_list *lst = ft_lstnew("first");
	t_list *student0 = ft_lstnew("student0");
	t_list *student1 = ft_lstnew("student1");
	t_list *student2 = ft_lstnew("student2");

	ft_lstadd_front(&lst, student0);
	ft_lstadd_front(&lst, student1);
	ft_lstadd_front(&lst, student2);

	printf("ft_:%s", ft_lstlast(lst)->content);
}
*/