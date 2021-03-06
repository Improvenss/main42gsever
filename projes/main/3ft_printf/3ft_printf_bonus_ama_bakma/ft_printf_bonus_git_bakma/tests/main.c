/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:37:37 by aperez-b          #+#    #+#             */
/*   Updated: 2021/10/16 11:52:20 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <limits.h>

/* ******** Leaks ******** */
void	check_leaks(int argc, char *uname)
{
	if (!ft_strncmp(uname, "Linux", 5))
		system("valgrind -q -s --leak-check=full --show-leak-kinds=all\
		--track-origins=yes ./a.out");
	else
		system("leaks a.out && ./a.out");
	ft_printf("Finished checking leaks on %s!\n", uname);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		check_leaks(argc, argv[1]);
	else
	{
		printf("Len: %d\n", ft_printf("ft_printf: %p\n", &argc));
		printf("Len: %d\n", printf("og_printf: %p\n", &argc));
	}
}
