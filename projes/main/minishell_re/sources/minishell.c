/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:57:07 by akaraca           #+#    #+#             */
/*   Updated: 2022/09/08 16:48:12 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_main	*g_main;
/*
// gcc minishell.c ../includes/minishell.h -lreadline && ./a.out
// gcc -Wall -Werror -Wextra minishell.c ../includes/minishell.h  -lreadline -o minishell && ./minishell
// gcc minishell.c ../includes/minishell.h -lreadline -L .brew/opt/readline/lib -I .brew/opt/readline/include && ./a.out

//brew goinfire'a kurulu ise; gcc minishell.c -L/goinfre/homebrew/opt/readline/lib -I/goinfre/homebrew/opt/readline/include -lreadline && ./a.out
//brew dosyalarını alt dizinde çalıştırmak istiyorsan; gcc minishell.c -L../includes/readline/lib -I../includes/readline/include -lreadline && ./a.out //mac'de kullanmak readline kütüphanesi sil yeniden kur(zip).
*/

void	ft_env_struct(char *env_arg)
{
	t_env	*new;
	t_env	*temp;
	int		i;

	new = (t_env *)malloc(sizeof(t_env));
	new->data = ft_split(env_arg, '=');
	new->next = NULL;
	if (new->data[2] != NULL)
	{
		i = 1;
		while (new->data[++i] != NULL)
			new->data[1] = ft_strjoin(ft_strjoin(new->data[1], "="), new->data[i]);
		new->data[2] = NULL;
	}
	if (g_main->env == NULL)
	{
		g_main->env = new;
		g_main->env->next = NULL;
	}
	else
	{
		temp = g_main->env;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_argument_set()
{
	extern char	**environ;
	int			i;
	
	g_main->environ = environ;
	g_main->env = NULL;
	i = -1;
	while (g_main->environ[++i])
	{
		ft_env_struct(g_main->environ[i]);
		printf("%s\n", g_main->environ[i]);
	}
}

int main(void)
{
	ft_argument_set();
}
