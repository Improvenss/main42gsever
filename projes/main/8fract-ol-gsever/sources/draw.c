/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:51:03 by gsever            #+#    #+#             */
/*   Updated: 2022/05/26 17:40:32 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/minilibx_opengl/mlx.h"

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
	mlx_loop(mlx_ptr);
}