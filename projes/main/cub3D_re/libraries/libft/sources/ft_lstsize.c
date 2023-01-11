/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:35:45 by gsever            #+#    #+#             */
/*   Updated: 2022/06/13 23:17:38 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//listedeki eleman sayisini bulur
int	ft_lstsize(t_list *lst)
{
	size_t	count;

	count = 0;
	while (lst && ++count)
		lst = lst->next;
	return (count);
}
/*
int	main()
{
	t_list *lst = ft_lstnew("start");
	t_list *student0 = ft_lstnew("student0");
	t_list *student1 = ft_lstnew("student1");
	t_list *student2 = ft_lstnew("student2");

	ft_lstadd_front(&lst, student0);
	ft_lstadd_front(&lst, student1);
	ft_lstadd_front(&lst, student2);

	printf("ft_:%d", ft_lstsize(lst));
}
*/