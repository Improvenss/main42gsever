/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_env_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:50:31 by gsever            #+#    #+#             */
/*   Updated: 2022/10/27 13:15:11 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*env_expand_seperate_second(t_base *base, char *new)
{
	if (new == NULL)
		return (ft_strdup("$"));
	else
	{
		base->mem_1 = new;
		base->mem_2 = ft_strjoin(new, "$");
		free(base->mem_1);
		return (base->mem_2);
	}
	return (new);
}

char	*env_expand_next(t_base *base, char *token, int *i, char *new)
{
	(*i)++;
	if (token[*i] == '\0')
	{
		return (env_expand_seperate_second(base, new));
	}
	if (token[*i] == '?')
	{
		(*i)++;
		if (new == NULL)
			return (ft_itoa(exit_status(0, 1)));
		else
		{
			base->mem_1 = ft_itoa(exit_status(0, 1));
			base->mem_2 = ft_strjoin(new, base->mem_1);
			free(base->mem_1);
			free(new);
			return (base->mem_2);
		}
	}
	if (ft_strchr(WHITESPACES, token[*i]))
	{
		(*i)++;
		return (ft_chrjoin("$", token[*i - 1]));
	}
	return (env_expand_next_next(base, token, i, new));
}

static void	env_expand_seperate_first(t_base *base,
	char **new, char *token, int *i)
{
	while (token[*i] == '$' && token[*i + 1] == '$')
	{
		*i = *i + 2;
		if (*new == NULL)
			*new = ft_strdup("$");
		else
		{
			base->mem_1 = *new;
			*new = ft_strjoin(*new, "$");
			free(base->mem_1);
		}
	}
}

char	*env_expand(t_base *base, char *token, int i, int l)
{
	char	*new;

	new = NULL;
	while (token[i])
	{
		l = i;
		while (token[i] != '$' && token[i])
			i++;
		if (i > 0 && new == NULL)
			new = ft_substr(token, 0, i);
		else if (i > l)
		{
			base->mem_1 = ft_substr(token, l, i - l);
			base->mem_2 = new;
			new = ft_strjoin(new, base->mem_1);
			free(base->mem_1);
			free(base->mem_2);
		}
		env_expand_seperate_first(base, &new, token, &i);
		if (token[i] == '$')
			new = env_expand_next(base, token, &i, new);
	}
	free(token);
	return (new);
}
