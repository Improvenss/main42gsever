/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:47:50 by gsever            #+#    #+#             */
/*   Updated: 2022/05/25 15:19:47 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
	NOT:	int main'lerde return(0) basarili bir donus demektir,
		return(1) basarisiz donus demektir.
*/
/*
	Programimiza int arguman sayimizi ve char pointerli char ya da string'i
 gonderdik.
	Programimizi yapay zeka kontrol etmiyor, sadece insanlar kontrol edecek.
	Fractal'larin calismasi icin 2 parametre gerekiyor;
		1-
		2-
		
*/
int	main(int argc, char *argv[])
{
	int	i;

	if (argc >= 2 && argc <= 11)
	{
		i = 1;
		while (i < argc)
		{
			if (!get_formula(argv[i]))
				break ;
			i++;
		}
		if (i == argc)
			start(argc - 1, &argv[1]);
	}
	print_help();
	return (0);
}
