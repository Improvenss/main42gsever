/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:33:22 by gsever            #+#    #+#             */
/*   Updated: 2022/08/02 13:57:44 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file philosophers.h
 * @brief Libraries for 'philosophers' project.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//	STANDARD LIBRARY INCLUDES
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <errno.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/time.h>
# include <pthread.h>

//	MY OWN 42 LIBRARIES
# include "../libraries/libft/includes/libft.h"

//	COLORS --> 🟥 🟩 🟦
# define LB		"\033[0;36m"
# define BLUE	"\033[0;34m"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define RESET	"\033[0m"
# define X		"\033[m"

/* ************************************************************************** */
/* STRUCT DEFINES AREA													  	  */
/* ************************************************************************** */

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

// void	philosophers(int argc, char **argv, t_base base);

#endif
