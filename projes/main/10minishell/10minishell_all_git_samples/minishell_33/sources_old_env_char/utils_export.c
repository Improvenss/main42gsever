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
