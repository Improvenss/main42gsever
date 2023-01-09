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

/** NORMOK:
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

static int	export_same_check_part_two(t_base *base, char *str,
	char *data_1, char *data_2)
{
	t_env	*check;

	check = base->env;
	while (check != NULL)
	{
		if (ft_strcmp_edited(data_1, check->data[0]) == 0)
		{
			if (ft_strchr(str, '='))
			{
				check->is_env_equal = true;
				free(check->data[1]);
				check->data[1] = data_2;
			}
			else
			{
				check->is_env_equal = false;
				free(data_2);
			}
			free(data_1);
			return (0);
		}
		check = check->next;
	}
	return (1);
}

int	export_same_check(t_base *base, char *str)
{
	char	*data_1;
	char	*data_2;

	data_1 = find_chr_ret_str(str, '=', false);
	if (!ft_strcmp_edited(data_1, "_"))
	{
		free(data_1);
		return (0);
	}
	data_2 = find_chr_ret_str(str, '=', true);
	if (export_same_check_part_two(base, str, data_1, data_2) == 0)
		return (0);
	free(data_1);
	free(data_2);
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

	tmp = base->env;
	max = tmp->data[0];
	while (tmp != NULL)
	{
		if (ft_strcmp_edited(max, tmp->data[0]) < 0)
			max = tmp->data[0];
		tmp = tmp->next;
	}
	return (max);
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
