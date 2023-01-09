/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:01:42 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/19 15:18:31 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	lexer_syntax(t_lexer *lexer)
{
	while (lexer)
	{
		if (lexer->flag == TOK_REDIR || lexer->flag == TOK_HEREDOC)
		{
			if (lexer->next == NULL || !(lexer->next->flag & (TOK_TEXT | TOK_D_QUOTE | TOK_S_QUOTE | TOK_REDIR_FILE))
			||	lexer->next->flag & (TOK_REDIR | TOK_HEREDOC))
				return (print_error(SHELLNAME, ERR_SYNTAX, NULL, ERR_REDIR)); // aa >'\0' veya a >>>'\0' veya a <<< b'\0'
		}
		if (lexer->flag == TOK_PIPE)
			if (lexer->next == NULL || !(lexer->next->flag & (TOK_TEXT | TOK_D_QUOTE | TOK_S_QUOTE)) || lexer->prev == NULL)
				return (print_error(SHELLNAME, ERR_SYNTAX, NULL, ERR_PIPE));
		lexer = lexer->next;
	}
	return (0);
}
