/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:03:34 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/15 22:03:34 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file utils_env.c
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

int	env_datalen(char **data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (data[i] && ft_strncmp_edited(data[i], "", 0))
	{
		len = len + ft_strlen(data[i]);
		i++;
	}
	return (len);
}

char	*env_data_ret(char **data)
{
	char	*ret;
	int		i;
	int		l;
	int		k;

	ret = (char *)malloc(sizeof(char) * (env_datalen(data) + 2));
	if (!ret)
		return (NULL);
	i = 0;
	k = 0;
	while (data[i] != NULL)
	{
		l = 0;
		while (data[i][l] != '\0')
		{
			ret[k] = data[i][l];
			k++;
			l++;
		}
		if (i == 0)
		{
			ret[k] = '=';
			k++;
		}
		i++;
	}
	ret[k] = '\0';
	return (ret);
}

char	**env_struct_to_char(t_env *env)
{
	char	**tmp;
	int		i;
	t_env	*env_tmp;

	tmp = (char **)malloc(sizeof(char *) * env_strlen(env) + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	env_tmp = env;
	while (env_tmp != NULL)
	{
		tmp[i] = env_data_ret(env_tmp->data);
		i++;
		env_tmp = env_tmp->next;
	}
	tmp[i] = NULL;
	return (tmp);
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
	while(tmp)
	{
		if (ft_strncmp(tmp->data[0], env_var, ft_strlen(env_var)) == 0
			&& ft_strncmp(tmp->data[1], value, ft_strlen(value)) == 0)
			return (true);
		tmp = tmp->next;
	}
	return (false);
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
	int		exit;

	exit = 0;
	tmp = base->env;
	while (tmp != NULL && exit == 0)
	{
		if (ft_strcmp_edited(env_name, tmp->data[0]) == 0)
		{
			tmp->data[1] = new_str;
			exit = 1;
		}
		tmp = tmp->next;
	}
}

char	*env_findret(t_base *base, char *env_name)
{
	t_env	*tmp;

	tmp = base->env;
	while (tmp != NULL)
	{
		if (ft_strcmp_edited(env_name, tmp->data[0]) == 0)
			return (tmp->data[1]);
		tmp = tmp->next;
	}
	return (NULL);
}

int	env_struct(t_base *base, char *new_arg)
{
	t_env	*new;
	t_env	*temp;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (ERROR);
	new->is_env_equal = false;
	if (ft_strncmp(new_arg, "=", 1))
		new->is_env_equal = true;
	new->data = ft_split(new_arg, '=');
	new->next = NULL;
	if (base->env == NULL)
	{
		base->env = new;
		base->env->next = NULL;
	}
	else
	{
		temp = base->env;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (0);
}
