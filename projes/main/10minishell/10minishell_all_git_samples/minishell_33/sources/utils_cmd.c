/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:22:13 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/19 15:26:42 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int cmd_count(t_cmd *cmd)
{
	int i;
	t_cmd *tmp;

	i = 0;
	tmp = cmd;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	*str_add(char *tmp, char *str)
{
	char *mem_1;
	char *mem_2;

	mem_1 = ft_strjoin(str, "\n");
	if (tmp == NULL)
		return (mem_1);
	mem_2 = ft_strjoin(tmp, mem_1);
	free(mem_1);
	if (tmp != NULL)
		free(tmp);
	return (mem_2);
}

void	cmd_lstadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd *tmp;

	tmp = *lst;
	if (*lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}
