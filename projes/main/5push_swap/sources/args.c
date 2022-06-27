/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:49:37 by gsever            #+#    #+#             */
/*   Updated: 2022/06/27 22:02:38 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief	Check arguments, is the argument just an integer?
 * Checking if arguman count 2 or +.
 * @return	void
 * @param	check_num --> ./push_swap 9 8 -3 2 -7 5 -> Looking ("").
 * @param	check_num_double_quotation --> ./push_swap "9 8 -3 2 -7 5"
 * @bug		Not know bugs.
 */
void	arg_checker(int argc, char **argv, t_base *base)
{
	if (argc > 2)
	{
		base->start.size = argc - 1;
		check_num(argc, argv);
		return ;
	}
	else if (argc == 2)
		check_num_double_quotation(argv[1], base);
}
