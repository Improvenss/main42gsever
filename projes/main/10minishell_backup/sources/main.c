/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:07:31 by gsever            #+#    #+#             */
/*   Updated: 2022/09/10 18:14:54 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	// t_main	main;
	char	*str = "ben gorkem sever";
	char	**str_split = (char **)malloc(sizeof(ft_strlen(str)));

	str_split = ft_split(str, ' ');
	printf("1. str -> %s\n", *str_split++);
	printf("2. str -> %s\n", *str_split++);
	printf("3. str -> %s\n", *str_split++);
	free(str_split);
	exit(1);
}