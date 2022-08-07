/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:10:43 by gsever            #+#    #+#             */
/*   Updated: 2022/08/07 22:20:18 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file error.c
 * @author Gorkem SEVER (gsever)
 * @brief Error page here.
 * @version 0.1
 * @date 2022-08-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/philosophers.h"

/**
 * @brief Write "string" terminal
 * @return 1
 * @bug Clear.
 */
int	ft_perror(char *str)
{
	(void)*str;
	exit(1);
	return(1);
}