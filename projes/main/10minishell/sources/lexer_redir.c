/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:50:43 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/26 23:07:24 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file lexer_redir.c
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

static int	redir_type(char *token)
{
	if (ft_strncmp_edited(token, "<", 1))
		return (TOK_REDIR);
	if (ft_strncmp_edited(token, ">", 1))
		return (TOK_REDIR);
	if (ft_strncmp_edited(token, "<<", 2))
		return (TOK_HEREDOC);
	if (ft_strncmp_edited(token, ">>", 2))
		return (TOK_HEREDOC);
	return (1);
}

int	lexer_redir(t_base *base, char *str, int *i)
{
	char	*token;
	int		len;
	t_lexer	*new;

	len = 0;
	while (ft_isdigit(str[*i + len]))
		len++;
	if (str[*i + len] == '<' || str[*i + len] == '>')
	{
		if (str[*i + len] == str[*i + len + 1])
			len++;
		len++;
		token = ft_substr(str, *i, len);
		if (!token)
			return (print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM)));
		new = token_create(base, token, redir_type(token));
		if (!new)
			return (print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM)));
		*i = *i + len;
	}
	return (0);
}
