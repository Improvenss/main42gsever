/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:31:49 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/27 17:15:50 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != '\0') && (*s1 == *s2) && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0 && *s1 == '\n')
		return (1);
	else
		return (0);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	ft_place_check(t_list *list_a)
{
	t_list	*temp;

	temp = list_a;
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	ft_exit(int error)
{
	if (error == 1)
		write(1, "Error\n", 7);
	else if (error == 2)
		write(1, "KO\n", 3);
	else if (error == 3)
		write(1, "OK\n", 3);
	exit(error);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
