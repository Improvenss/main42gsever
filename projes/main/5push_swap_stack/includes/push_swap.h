/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:02:31 by gsever            #+#    #+#             */
/*   Updated: 2022/08/22 02:16:57 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file push_swap.h
 * @brief Libraries for 'push_swap' project.
 * @author Görkem SEVER (gsever)
 * @bug Not know bugs.
 */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//	STANDARD LIBRARY INCLUDES
# include <unistd.h> /*
	read(),
	write()
*/
# include <stdlib.h>/*
	malloc(),
	free(),
	exit()
*/


//	MY OWN 42 LIBRARIES
# include "../libraries/libft/includes/libft.h"

//	ERROR CODES
# define NO_ARGS -1
# define INVALID_INPUT -2
# define STACK_EMPTY -3
# define STACK_ITEM_DOES_NOT_EXIST -4

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

/**
 * @brief For one number's struct.
 * @param data : Number's value.
 * @param next* : Pointing next number in stack.
 */
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}			t_stack;


typedef struct s_base
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		
}			t_base;

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */



#endif
