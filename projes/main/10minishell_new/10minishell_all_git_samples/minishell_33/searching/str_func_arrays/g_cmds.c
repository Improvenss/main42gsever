/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_cmds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:46:35 by gsever            #+#    #+#             */
/*   Updated: 2022/09/30 20:23:07 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

struct s_commands
{
	char	*name;
	int		(*func)(int a);
};

struct s_commands	g_commands[] = {
	{"echo", cmd_echo},
	{"cd", cmd_cd},
	{"pwd", cmd_pwd},
	// {"env", cmd_env},
	// {"export", cmd_export},
	// {"unset", cmd_unset},
	{NULL, NULL},
};

int	cmd_echo(int a)
{
	printf("inside cmd_echo(%d)\n", a);
	return (0);
}

int	cmd_cd(int a)
{
	printf("inside cmd_cd(%d)\n", a);
	return (0);
}

int	cmd_pwd(int a)
{
	printf("inside cmd_pwd(%d)\n", a);
	return (0);
}
int	main()
{
	int		cmd_len;
	char	*input = "ben echo gorkem";
	int	i = 0;

	// while (g_commands[i] != NULL)
	// {
	// 	cmd_len = strlen(g_commands[i].name);
	// 	if (strncmp(input, g_commands[i].name, cmd_len + 1));
	// }
	return (g_commands[0].func(5));
}