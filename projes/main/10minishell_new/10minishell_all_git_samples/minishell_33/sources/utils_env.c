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

	ret = (char *)malloc(sizeof(char) * (env_datalen(data) + 1));
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
 * @note int stop; kullanilmiyor.
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
			break;
		}
		tmp = tmp->next;
	}
	if (status == false)
		free(new_str);
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

char	*find_chr_ret_str(char *str, char c, bool status)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			break;
	}
	if (status == true)
	{
		if (str[i] == '\0')
			return (NULL);
		else
			return (ft_substr(str, i + 1, ft_strlen(str)));
	}
	return (ft_substr(str, 0, i));
}

int	env_size(char *src)
{
	char	*data_1;
	char	*data_2;

	data_1 = find_chr_ret_str(src, '=', false);
	data_2 = find_chr_ret_str(src, '=', true);
	if (data_2 == NULL)
	{
		free(data_1);
		return (1);
	}
	else if (data_1 && data_2)
	{
		free(data_1);
		free(data_2);
		return (2);
	}
	return (0);
}

char	**env_split(char *src)
{
	char	**dst;

	dst = NULL;
	dst = (char **)malloc(sizeof(char *) * (3));
	if (!dst)
	{
		print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM));
		return(NULL);
	}
	dst[0] = find_chr_ret_str(src, '=', false);
	dst[1] = find_chr_ret_str(src, '=', true);
	dst[2] = NULL;
	return (dst);
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
	new->data = env_split(new_arg);
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
