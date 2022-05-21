/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-bakk <pde-bakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:55:31 by pde-bakk          #+#    #+#             */
/*   Updated: 2022/03/01 15:01:35 by pde-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "libft.h"

static void	error(t_collection *coll)
{
	(void)coll;
	ft_putendl_fd("Error. Bad instruction", STDERR_FILENO);
}

t_opcode	string2opcode(const char *str)
{
	unsigned long int	i;
	static char *const	opcode_strings[] = {
	[SA] = "sa", [SB] = "sb", [SS] = "ss",
	[PA] = "pa", [PB] = "pb",
	[RA] = "ra", [RB] = "rb", [RR] = "rr",
	[RRA] = "rra", [RRB] = "rrb", [RRR] = "rrr"
	};

	i = 0;
	if (ft_strlen(str) < 2 || ft_strlen(str) > 3)
		return (ERROR);
	while (i < sizeof(opcode_strings) / sizeof(*opcode_strings))
	{
		if (!ft_strncmp(str, opcode_strings[i], ft_strlen(str)))
		{
			return (i);
		}
		++i;
	}
	return (ERROR);
}

void	print_operation(const t_opcode opcode, const int fd)
{
	static char *const	op_stringcodes[] = {
	[SA] = "sa", [SB] = "sb", [SS] = "ss",
	[PA] = "pa", [PB] = "pb",
	[RA] = "ra", [RB] = "rb", [RR] = "rr",
	[RRA] = "rra", [RRB] = "rrb", [RRR] = "rrr", [ERROR] = "Error"
	};

	if (opcode != ERROR)
	{
		ft_putendl_fd(op_stringcodes[opcode], fd);
	}
}

void	execute_operation(t_opcode opcode, t_collection *collection)
{
	static const t_operation	operations[] = {
	[SA] = &sa, [SB] = &sb, [SS] = &ss,
	[PA] = &pa, [PB] = &pb,
	[RA] = &ra, [RB] = &rb, [RR] = &rr,
	[RRA] = &rra, [RRB] = &rrb, [RRR] = &rrr, [ERROR] = &error
	};

	operations[opcode](collection);
}
