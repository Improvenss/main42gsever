/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:13:35 by gsever            #+#    #+#             */
/*   Updated: 2021/12/15 22:27:04 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
typedef struct s_stock_str
{
int size;
char *str;
char *copy;
} t_stock_str;
*/
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*t;
	int			i;

	if (ac < 0)
		ac = 0;
	t = malloc((ac + 1) * sizeof(t_stock_str));
	if (!t)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		t[i].size = ft_strlen(av[i]);
		t[i].str = av[i];
		t[i].copy = ft_strdup(av[i]);
	}
	t[i].str = 0;
	return (t);
}
/*
#include <stdio.h>
void	ft_show_tab(struct s_stock_str *par)
{
	if (!par)
		return ;
	while (par->str)
	{
		printf("%s\n", (par->str));
		printf("%d\n", (par->size));
		printf("%s\n", (par->copy));
		par++;
	}
}
int	main()
{
	char *a[] = {"ali", "fatih", "gorkem"};
	t_stock_str *strler = 	ft_strs_to_tab(3, a);
	ft_show_tab(strler);	
}
*/
