/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:51:28 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/20 19:58:20 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	text_lenght(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_strchr(WHITESPACES, str[i]))
			break;
		else if (other_lenght(&str[i]) > 0)
			break;
		else if (ft_strchr(QUOTE_MARKS, str[i]))
			break;
	}
	return (i);
}

int	lexer_text(t_base *base, char *str, int *i)
{
	char 	*token;
	int		len;
	t_lexer	*new;
	t_lexer	*last;

	len = text_lenght(&str[*i]);
	if (len > 0)
	{
		token = ft_substr(str, *i, len);
		if (ft_strchr(token, '$'))
			token = env_expand(base, token);
		last = lexer_lstlast(base->lexer);
		if (last && last->flag & TOK_CONNECTED)
		{
			*i = *i + len;
			node_merge(&last, token, str, i);
			return (0);
		}
		if(!token)
			return (print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM)));
		new = token_create(base, token, lexer_type(last, TOK_TEXT));
		if (!new)
			return (print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM)));
		*i = *i + len;
		if (!ft_strchr(WHITESPACES, str[*i]) && other_lenght(&str[*i]) == 0)
			new->flag |= TOK_CONNECTED;
	}
	return (0);
}
