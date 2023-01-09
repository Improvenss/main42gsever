/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:59:26 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/27 09:01:14 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file utils_command.c
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

char	*ft_path(char **path, char *cmd_name)
{
	char	*dir1;
	char	*dir2;
	int		i;

	i = -1;
	if (path == NULL)
		return (NULL);
	while (path[++i])
	{
		dir2 = ft_strjoin("/", cmd_name);
		dir1 = ft_strjoin(path[i], dir2);
		free(dir2);
		if (access(dir1, 0) == 0)
		{
			return (dir1);
		}
		free(dir1);
	}
	return (NULL);
}

int	file_or_dir_search(char *str, int flag)
{
	int	fd;

	fd = open(str, flag);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	search_and_launch(char **cmd_array)
{
	if (ft_strncmp(cmd_array[0], "./", 2))
		return (0);
	if (!file_or_dir_search(cmd_array[0], 0))
		return (0);
	return (1);
}
