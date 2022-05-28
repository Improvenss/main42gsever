/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:51:03 by gsever            #+#    #+#             */
/*   Updated: 2022/05/27 19:31:44 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


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
	if(MAINP_ESC)
	{
		mlx_destroy_window(mlx_ptr, win_ptr);
		mlx_destroy_image(mlx_ptr, win_ptr);
		free(mlx_ptr);
		free(win_ptr);
	}
	mlx_loop(mlx_ptr);
}