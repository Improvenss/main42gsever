/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:18:58 by akaraca           #+#    #+#             */
/*   Updated: 2022/05/27 19:54:36 by akaraca          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_with_error(const char *str)
{
	int		sign;
	long	val;

	sign = 1;
	val = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		val = (val * 10) + (*str - '0');
		str++;
	}
	val = val * sign;
	if (val >= -2147483648 && val <= 2147483647)
		return (val);
	else
		ft_exit(1);
	return (0);
}

t_list	*ft_argv_to_list(t_list *list_a, char *value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = ft_atoi_with_error(value);
	new->next = list_a;
	list_a = new;
	new = new->next;
	while (new != NULL)
	{
		if (list_a->data == new->data)
			ft_exit(1);
		new = new->next;
	}
	new = NULL;
	return (list_a);
}

int	ft_rule_check(char *tmp)
{
	size_t	i;

	i = 0;
	while ((((tmp[i] >= '0' && tmp[i] <= '9' ) || tmp[i] == ' ' \
					|| tmp[i] == '-' || tmp[i] == '\0')) && i < ft_strlen(tmp))
	{
		if ((tmp[i] == '-' && tmp[i + 1] == ' ') \
				|| (tmp[i] == '-' && tmp[i + 1] == '0') \
				|| (tmp[i] == '-' && tmp[i + 1] == '-') \
				|| (tmp[i] == '-' && tmp[i + 1] == '\0'))
			return (1);
		i++;
		if (i == ft_strlen(tmp))
			return (0);
	}
	return (1);
}

char	*ft_strjoin(char *save, char *buffer)
{
	char	*temp;
	int		i;
	int		l;

	if (!save)
	{
		save = (char *)malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(save) +\
				ft_strlen(buffer) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (save[i] != '\0')
	{
		temp[i] = save[i];
		i++;
	}
	l = 0;
	while (buffer[l] != '\0')
		temp[i++] = buffer[l++];
	temp[i] = '\0';
	free(save);
	return (temp);
}

void	ft_string_check(int argc, char **argv)
{
	char		*tmp;

	tmp = NULL;
	while (argc--)
	{
		tmp = ft_strjoin(tmp, *argv);
		tmp = ft_strjoin(tmp, " ");
		argv++;
	}
	tmp[ft_strlen(tmp) - 1] = '\0';
	if (ft_rule_check(tmp))
	{
		free(tmp);
		ft_exit(1);
	}
	free(tmp);
}
