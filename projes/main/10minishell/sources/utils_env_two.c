/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:43:29 by gsever            #+#    #+#             */
/*   Updated: 2022/10/27 13:15:38 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file utils_env_two.c
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

char	*env_findret_no_dup(t_base *base, char *env_name)
{
	t_env	*tmp;

	tmp = base->env;
	while (tmp != NULL)
	{
		if (ft_strcmp_edited(env_name, tmp->data[0]) == 0)
		{
			if (tmp->data[1] != NULL)
				return (tmp->data[1]);
			else
				return (NULL);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

char	*env_findret(t_base *base, char *env_name)
{
	t_env	*tmp;

	tmp = base->env;
	while (tmp != NULL)
	{
		if (ft_strcmp_edited(env_name, tmp->data[0]) == 0)
		{
			if (tmp->data[1] != NULL)
			{
				return (ft_strdup(tmp->data[1]));
			}
			else
				return (NULL);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

/** OK:
 * @brief Environmentlerin icinde disaridan verdigimiz variable ve valuesini
 *  ariyoruz; eger varsa true donuyor, yoksa(bulamazsa) false donuyor.
 * 
 * @param base For base->env
 * @param env_var env -> [HERE]=not_here
 * @param value env -> [not_here]=[HERE]
 * @return If variable found OK: true. Not found NOK: false.
 */
bool	env_is_have(t_base *base, char *env_var, char *value)
{
	t_env	*tmp;

	tmp = base->env;
	while (tmp)
	{
		if (ft_strncmp(tmp->data[0], env_var, ft_strlen(env_var)) == 0
			&& ft_strncmp(tmp->data[1], value, ft_strlen(value)) == 0)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

int	env_strlen(t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**env_be_char(t_env *env)
{
	char	**new;
	t_env	*tmp;
	int		size;
	int		i;

	i = 0;
	size = env_strlen(env);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	tmp = env;
	while (tmp != NULL)
	{
		new[i] = env_data(tmp);
		i++;
		tmp = tmp->next;
	}
	new[i] = NULL;
	return (new);
}
