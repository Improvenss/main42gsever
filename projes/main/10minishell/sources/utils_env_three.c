/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:47:20 by gsever            #+#    #+#             */
/*   Updated: 2022/10/26 23:53:37 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file utils_env_three.c
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

char	*env_data(t_env *tmp)
{
	char	*new;
	char	*del;

	new = ft_strdup(tmp->data[0]);
	if (tmp->is_env_equal == true)
	{
		del = new;
		new = ft_strjoin(new, "=");
		free(del);
	}
	if (tmp->data[1] != NULL)
	{
		del = new;
		new = ft_strjoin(new, tmp->data[1]);
		free(del);
	}
	return (new);
}

/**
 * @brief Set the env object
 * 
 * @param base 
 * @param env_name 
 * @param new_str 
 * @note int exit; kullanilmiyor.
 */
void	set_env(t_base *base, char *env_name, char *new_str)
{
	t_env	*tmp;
	char	*del;
	bool	status;

	tmp = base->env;
	status = false;
	while (tmp != NULL)
	{
		if (ft_strcmp_edited(env_name, tmp->data[0]) == 0)
		{
			status = true;
			del = tmp->data[1];
			if (new_str != NULL)
				tmp->data[1] = ft_strdup(new_str);
			else
				tmp->data[1] = NULL;
			free(new_str);
			free(del);
			break ;
		}
		tmp = tmp->next;
	}
	if (status == false)
		free(new_str);
}
