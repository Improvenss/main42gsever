/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:37:31 by gsever            #+#    #+#             */
/*   Updated: 2023/01/11 23:37:07 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @author Ahmet KARACA (akaraca)
 * @author Görkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-11-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/cub3d.h"

/**
 * @brief 
 * 
* ************************************************************************** *
						✓
Aciklama:
		Birinci şahıs bakış açısıyla bir labirentin içinin "gerçekçi"
	 bir 3D grafik gösterimini oluşturmalısınız. Bu gösterimi daha önce
	 bahsedilen Işın Takibi(Ray Casting) ilkesini kullanarak oluşturmalısınız.

Kısıtlamalar aşağıdaki gibidir:
	• miniLibX kullanmanız gerekiyor. Ya işletim sisteminde bulunan sürümü
 ya da kendi kaynaklarındaki sürümü kullanın. Kaynaklarla çalışmayı seçerseniz,
 libft için yukarıda Ortak Talimatlar bölümünde yazılanlarla aynı kuralları
 uygulamanız gerekir.
	• Pencere kontrolünüz başka bir pencereye geçme, küçültme vb. durumlarda
 akıcı olmalıdır.
	• Duvarın hangi tarafa baktığına (Kuzey, Güney, Doğu, Batı) bağlı olarak
 değişen farklı duvar dokuları sergileyin (seçim sizin).
	• Programınız zemin ve tavan renklerini iki farklı renge
 ayarlayabilmelidir.
	• Program görüntüyü bir pencerede gösterir ve aşağıdaki kurallara uyar:
		◦ Klavyenin sol ve sağ ok tuşları labirentte sola ve sağa bakmanıza
	 izin vermelidir.
		◦ W, A, S ve D tuşları, bakış açısını labirentte hareket ettirmenize
	 izin vermelidir.
		◦ ESC’ye basmak pencereyi kapatmalı ve programdan temiz bir şekilde
	 çıkmalıdır.
		◦ Pencere çerçevesindeki kırmızı çarpı işaretine tıklamak pencereyi
	 kapatmalı ve programdan temiz bir şekilde çıkmalıdır.
		◦ minilibX kullanılması şiddetle önerilmektedir.
	• Programınız ilk argüman olarak bir harita dosyasını .cub
 uzantısıyla almalıdır.
		◦ Harita 6 olası karakterden oluşmalıdır:
			Boş alanlar için 0,
			Duvarlar için 1,
			ve kullanıcının başlangıç pozisyonu
			ve yeniden doğma yönü için N,S,E veya W
			 Basit ve geçerli bir harita örneği:
				111111
				100101
				101001
				1100N1
				111111
		◦ Harita kapalı veya duvarlarla çevrili olmalı, değilse program bir
	 hata vermelidir.
		◦ Harita içeriği dışında, her öğe türü bir veya daha fazla boş
	 satırla ayrılabilir.
		◦ Her zaman en son olması gereken harita içeriği dışında,
	 her öğe türü dosyada herhangi bir sırada ayarlanabilir.
		◦ Harita dışında, bir öğeden gelen her bilgi türü bir veya daha
	 fazla boşlukla ayrılabilir.
		◦ Harita, dosyada göründüğü gibi ayrıştırılmalıdır.
	 Boşluklar haritanın geçerli bir parçasıdır ve işlemek size kalmıştır.
	 Harita kurallarına uyduğu sürece her tür haritayı
	 ayrıştırabilmeniz gerekir.
		◦ Her öğenin (harita hariç) ilk bilgileri, tür tanımlayıcısıdır
	 (bir veya iki karakterden oluşur), ardından her nesne için kesin bir
	 sırayla tüm özel bilgiler gelir, örneğin:
			∗ North texture(Kuzey dokusu):
	Usage: ->	NO ./path_to_the_north_texture (XPM file format)
			∗ South texture(Güney dokusu):
	Usage: ->	SO ./path_to_the_south_texture (XPM file format)
			∗ West texture(Batı dokusu):
	Usage: ->	WE ./path_to_the_west_texture (XPM file format)
			∗ East texture(Doğu dokusu):
	Usage: ->	EA ./path_to_the_east_texture (XPM file format)
			∗ Zemin rengi: (R,G,B [0,255] aralığında: 0, 255, 255)
	Usage: ->	F 220,100,0
			∗ İç kaplama rengi: (R,G,B [0,255] aralığında: 0, 255, 255)
	Usage: ->	C 225,30,0
		◦ Dosyada herhangi bir yanlış yapılandırma ile karşılaşılırsa,
	 program düzgün bir şekilde kapanmalı ve seçtiğiniz açık bir hata
	 mesajının ardından "Error\n" döndürmelidir.

------------------------- BONUS PART -------------------------

Bonus listesi:
	• Duvar çarpmaları.
	• Mini harita sistemi.
	• Açılıp kapanabilen kapılar.
	• Animasyonlu spritelar.
	• Mouse yardımıyla bakış açısını değiştirme.

INFO: Değerlendirmeniz sırasında kullanımları serbest olduğu sürece,
bonus bölümünü tamamlamak için başka fonksiyonları kullanmanıza veya
haritaya semboller eklemenize izin verilmektedir.  Ayrıca, istenen
harita dosyası formatını ihtiyaçlarınıza göre değiştirebilirsiniz.
Akıllı davranın!

* ************************************************************************** *
 * 
 * TODO: OK:check, init, set
 * TODO: struct; map, minimap, mlx_window
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)
{
	t_main		main;

	printf(GREEN"Program started:"END YELLOW" Argumans checking...\n"END);
	if (check_args(argc, argv) == ERROR)
		return (1);
	printf(GREEN"Argumans checked OK:"END YELLOW" Map checking...\n"END);
	if (check_map(&main, argv) == ERROR)
		return (2);
	printf(GREEN"Map checking OK:"END YELLOW" MLX's window creating...\n"END);
	if (init_all(&main) == ERROR)
		return (3);
	printf(GREEN"MLX's window create OK:"END YELLOW" Going draw loop...\n"END);
	draw_mlx_window(&main);// inside the loop draw to mlx's img to window.
		return (4);
	return (0);
}
