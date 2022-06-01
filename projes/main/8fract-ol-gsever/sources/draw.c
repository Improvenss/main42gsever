/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:51:03 by gsever            #+#    #+#             */
/*   Updated: 2022/06/02 00:37:49 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/fractol.h"

/*
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
*/
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
/*
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
*/

/*
	Keyboard --> 9
*/
void	color_map(t_fractol *frctl)
{
	void	*win;
	int		x;
	int		y;
	int		w;
	int		h;
	int		color;

	//dobbe.ptr = mlx_init();
	win = mlx_new_window(frctl->mlx->ptr, SIZE_X, SIZE_Y, "Ur Mom Gay!");
	w = SIZE_X;
	x = w;
	while (x--)
	{
		h = SIZE_Y;
		y = h;
		while (y--)
		{
			color = (x * 255) / w + ((((w - x) * 255) / w) << 16) +
				(((y * 255) / h) << 8);
			mlx_pixel_put(frctl->mlx->ptr, win, x, y, color);
		}
	}
	//mlx_loop(frctl->mlx->ptr);
}
