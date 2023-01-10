/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:47:06 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/13 08:47:06 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** NORMOK:
 * @file minishell.c
 * @author Ahmet KARACA (akaraca)
 * @author Gorkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/minishell.h"

static void	minishell_part_2(t_base *base)
{
	if (lexer(base, base->input_line) != ERROR)
	{
		if (lexer_syntax(base->lexer) == ERROR)
			exit_status(2, 0);
		else
		{
			cmd(base);
			close_cmd_fd(base->cmd);
			free_fork_inits(base, base->fd);
			free_cmd(&base->cmd);
		}
		free_lexer(&base->lexer);
	}
	free(base->input_line);
}

/**
 * @brief Bash shell starting here.
 * 
 * @param base For main structure.
 * @fn signal(): Klayeden girilen CTRL+C,D,\ sinyallerini kontrol ediyor.
 * 	\:	signal(SIGQUIT, SIG_IGN); CTRL+\ signalini ignore'luyor.
 * 	C:	signal(SIGINT, action); CTRL+C signali PDF'de bizden PROMT'umuzu
 *  ve sonrasinda '\n' yapmamizi istiyor, onun icin kullaniliyor.
 * 	D:	CTRL+D -> readline()'den '\0'(NULL) donuyor, null oldugu icin
 *  base->input_line = NULL oluyor, boylelikle break ; ile while'den cikip
 *  exit atiyoruz.
 * @fn commands_init(): base->commands[8] -> bizden istenilen komutlari
 *  burada init ediyoruz. Func*'da cagirma imkani sunuyor.
 * @fn action(): CTRL+*'dan gelen sinyal sonucunda hangi func()
 *  calismasini istedigimiz func(). Burada CTRL+C sinyalinin prompt'u yazip
 *  '\n' yazmasini istiyoruz.
 * @fn readline(): T_NAME'yi ekrana bastirdiktan sonra; girdigimiz input'u
 *  '\n'leriyle birlike '\0'a kadar alarak return ediyor. Yani tek bir string.
 * @fn history_empty_check(): Onceki girdiyle simdiki girdimizi karsilastiriyor
 *  ayniysa hafizaya almiyor.
 * @fn add_history(): readline.h'in kendi func();
 *  gecmisi hafizasinda tutmaya yariyor.
 * @fn lexer(): base->input_line'den alinan girdimizi lexer'liyor.
 * @fn lexer_sytax(): Lexer'lenen girdimizde yazim(syntax) hatasi var mi
 *  kontrol ediyor, hata varsa exit status'u 1 yapiyor. Yoksa cmd() run.
 * @fn exit_status(): Exit status'umuzu(hafizada tuttugumuz cikis degerimiz)
 *  1 olarak guncelliyoruz.
 * @fn cmd(): Lexer, lexer_sytax islemlerinden sonra elimizdeki lexerlenmis
 *  veriyi calistirmaya gonderiyoruz. Tabii ki icinde expand & executor
 *  islemlerini yapiyor.
 * @fn lexer_free(): t_lexer struct'larimizi teker teker freeliyoruz.
 * @fn cmd_free(): t_cmd struct'larimizi teker teker freeliyoruz.
 * @fn free(): readline()'den alinan girdimizi freeliyoruz.
 * @fn all_free(): Geriye kalan her seyi freeliyoruz.
 * @note isatty(): Terminal(tty) var mi yok mu onu kontrol ediyor.
 * @note errno -> errno.h'ta tanimli errno; Donus degerlerini tutmak icin.
*/
void	minishell(t_base *base)
{
	signal(SIGQUIT, SIG_IGN);
	commands_init(base);
	while (1)
	{
		signal(SIGINT, action);
		termios_change(false);
		base->input_line = readline(T_NAME);
		if (!base->input_line)
		{
			termios_change(true);
			break ;
		}
		if (history_empty_check(base->input_line))
			add_history(base->input_line);
		minishell_part_2(base);
	}
	free_all(base);
}
