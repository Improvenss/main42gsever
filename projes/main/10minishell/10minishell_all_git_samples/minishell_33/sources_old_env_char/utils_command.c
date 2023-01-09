/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:59:26 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/21 15:48:44 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_path(char **path, char *cmd_name)
{
	char	*dir1;
	char	*dir2;
	int		i;

	i = -1;
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

	fd = open(str, flag); //NO_MATCH (0)-> Flag olarak bir tanımlıyıcıya ihtiyacımız yok, belirtilen dizin içerisinde dosya varlık yokluk kontrolü gereklidir. (windowsta var)
	close(fd);
	if (fd == -1) //dosya yok ise -1 döner.
		return (0);
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
