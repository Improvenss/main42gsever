/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:35:46 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/21 23:15:09 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	strncmp_to_chr(const char *s1, const char *s2, size_t n, char end)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1 && (*s1 != '\0') && (*s1 == *s2) && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0 && (s1[n] == '\0' || s1[n] == end))
		return (1);
	return (0);
}

int	env_strlen(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	*env_findret(char **env, char *env_name)
{
	char	*ret;
	int		i;

	ret = NULL;
	i = 0;
	while (env[i] && !strncmp_to_chr(env[i], env_name, ft_strlen(env_name), '='))
		i++;
	if (i != env_strlen(env))
		ret = ft_substr(env[i], ft_strlen(env_name) + 1, ft_strlen(env[i]) - ft_strlen(env_name));
	return (ret);
}

char	**set_env(char **src)
{
	char	**dst;
	int		i;

	dst = NULL;
	dst = (char **)malloc(sizeof(char *) * env_strlen(src) + 1);
	if (!dst)
	{
		print_error(SHELLNAME, NULL, NULL, strerror(ENOMEM));
		return(NULL);
	}
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
