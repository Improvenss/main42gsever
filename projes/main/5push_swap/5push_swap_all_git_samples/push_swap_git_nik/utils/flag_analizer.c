/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_analizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:54:15 by Nik               #+#    #+#             */
/*   Updated: 2019/08/30 22:08:28 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		flag_analizer(char **argv, t_push *flags)
{
	int	i;

	i = 1;
	ft_memset(flags, 0, sizeof(t_push));
	while (argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
	{
		if (ft_strequ(argv[i], "-e"))
			flags->e = 1;
		else if (ft_strequ(argv[i], "-g"))
		{
			flags->g = 1;
			flags->v = 1;
			flags->e = 1;
			flags->c = 1;
		}
		else if (ft_strequ(argv[i], "-c"))
			flags->c = 1;
		else if (ft_strequ(argv[i], "-v"))
			flags->v = 1;
		else
			ft_error("invalid flag");
		if (!argv[++i])
			break ;
	}
	return (i);
}
