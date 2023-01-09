/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:49:38 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/26 23:34:29 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file lexer_pipe.c
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

int	lexer_pipe(t_base *base, char *str, int *i)
{
	char	*token;
	t_lexer	*new;

	if (str[*i] == '|' && str[*i + 1] != '|' && str[*i - 1] != '|')
	{
		token = ft_substr(str, *i, 1);
		if (!token)
			return (print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM)));
		new = token_create(base, token, TOK_PIPE);
		if (!new)
		{
			free(token);
			return (print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM)));
		}
		(*i)++;
	}
	return (0);
}
