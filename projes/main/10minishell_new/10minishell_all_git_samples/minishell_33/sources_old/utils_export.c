/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:43:49 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/15 21:43:49 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file utils_export.c
 * @author Ahmet KARACA (akaraca)
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/minishell.h"

int	export_dot_slash_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
	{
		if (str[i] == '/' ||str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int	export_arg_check(char **str)
{
	int	i;
	int	l;

	i = 1;
	while (str[i])
	{
		l = 0;
		while (str[i][l])
		{
			if (l == 0 && (str[i][l] == '=' || export_dot_slash_check(str[i])))
			{
				print_error("export", str[i], NULL, "not a valid identifier");
				return (0);
			}
			l++;
		}
		i++;
	}
	return (1);
}

int	export_same_check(t_base *base, char *str)
{
	t_env	*check;
	char	**data;
	int		l;

	l = ft_strncmp(str, "=", 1);
	data = ft_split(str, '=');
	check = base->env;
	while (check != NULL)
	{
		if (ft_strcmp_edited(data[0], check->data[0]) == 0)
		{
			if (l != 0 && data[1] != NULL)
			{
				check->data[1] = data[1];
			}
			chr_free(data);
			return (0);
		}
		check = check->next;
	}
	chr_free(data);
	return (1);
}

int	export_lstsize(t_env *lst)
{
	size_t	count;

	count = 0;
	while (lst && ++count)
		lst = lst->next;
	return (count);
}

char	*export_find_max_str(t_base *base)
{
	t_env	*tmp;
	char	*max;
	//char	*max_before;

	tmp = base->env;
	max = tmp->data[0];
	while (tmp != NULL)
	{
		//max_before = max;
		if (ft_strcmp_edited(max, tmp->data[0]) < 0)
			max = tmp->data[0];
		tmp = tmp->next;
	}
	return (max);
	//return (max_before); //max = _ olduğundan dolayı bir önceki değeri döndürüyorum.
}

char	*export_find_min_str(t_base *base)
{
	t_env	*tmp;
	char	*min;

	tmp = base->env;
	min = tmp->data[0];
	while (tmp != NULL)
	{
		if (ft_strcmp_edited(min, tmp->data[0]) > 0)
			min = tmp->data[0];
		tmp = tmp->next;
	}
	return (min);
}
