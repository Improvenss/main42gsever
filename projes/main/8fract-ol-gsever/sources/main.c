/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:43:16 by gsever            #+#    #+#             */
/*   Updated: 2022/05/29 16:23:19 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
/*
	NOT:	int main'lerde return(0) basarili bir donus demektir,
		return(1) basarisiz donus demektir.
*/
/*
	mlx's functins means;
mlx_init()
	--> Yazilan program ile ekran arasindaki baglantiyi baslatir.
void * mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
	--> Ekrana pencere acmamizi saglar.
void *mlx_new_image(void *mlx_ptr, int width, int height);
	--> Goruntu olusturmak icin, eger olusursa void*'in tanimlayicisi dondurur.
char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
						int *size_line, int *endian);
	--> Olusturulan goruntunun adresini dondurur, eger basarili bir sekilde 
	donerse aldigi 3 parametreye deger atanir. Bu bilgilerde; pikselin rengini 
	ifade etmek icin gereken bit sayisi parametreye girilir. (Araci gibi)


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
	fractol(argc, argv);
	return (0);
}
