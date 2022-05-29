/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:51:03 by gsever            #+#    #+#             */
/*   Updated: 2022/05/28 18:10:15 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/fractol.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//	If pressed any key, writing X
int	deal_key(int key, void *param)
{
	ft_putchar('X');
	return(0);
}

/*
	For Compile; In termial we can build like this;
gcc -I ../libraries/minilibx_opengl draw.c -L ../libraries/minilibx_opengl/ 
 -lmlx -framework OpenGL -framework AppKit
	Terminal Codes Means;
		-I 		-->	include		-> su konumdaki dosyalari dahil et
		-L		-->	location	-> MinilibX icin kullanilir, konumunu 
			bildirmemiz gerek.
		-lmlx	-->	mlx kutuphanesini derlemek icindi sanirsam.
		-framework <fw's>	--> OpenGL and AppKit	-> apple'nin icindeki 
			framework'lari dahil edebilmek icin.
*/
int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "First Window");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}