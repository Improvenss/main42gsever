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

/** NORMOK:
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

char	*find_chr_ret_str(char *str, char c, bool status)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			break ;
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
		return (NULL);
	}
	dst[0] = find_chr_ret_str(src, '=', false);
	dst[1] = find_chr_ret_str(src, '=', true);
	dst[2] = NULL;
	return (dst);
}

/**
 * @brief base->env structu bossa yeni olusturulacak(ilk baslangictaki init),
 *  varsa yeni eklenecek env'yi sondaki linked-list'e ekleyecek.
 * 
 * @param base base->env structu icin.
 * @param new_arg Disaridan ekleyecegimiz env.
 * @fn malloc(): environment struct'u(env'nin 1 satiri icin) yer aciyoruz.
 * @fn ft_strncmp(): Yeni eklenecek env'da '=' varsa ture yapacagiz.
 * @fn ft_split(): env'nin ='in sol tarafi ve sag tarafi olacak sekilde,
 *  ayiriyoruz, data[0]=data[1] oluyor.
 * @return int OK: 0, NOK: ERROR
 */
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
