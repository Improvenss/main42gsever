/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:57:07 by akaraca           #+#    #+#             */
/*   Updated: 2022/08/24 18:12:09 by akaraca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <string.h>

# define BLACK "\e[0;30m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define PURPLE "\e[0;35m"
# define CYAN "\e[0;36m"
# define WHITE "\e[0;37m"
# define FINISH "\e[m"
# define APP_NAME ""GREEN"🅼 🅸 🅽 🅸 🆂 🅷 🅴 🅻 🅻 $"FINISH""
# define COMMAND_SIGN " "

/**
 * list yapısı içerisinde tutulacak
 * her yeni girdi sona eklenecek
 * her girdiye numara verilecek
 * her girdinin kendisine ait uzunluk verileri tutulacak
 * her girdi için malloc ile yer açılacak
 * 
 */
typedef struct s_history
{
	int			size;
	int			n;
	char		*data;
	struct s_history *next;

}t_history;

typedef struct s_main
{ 
	t_history *history;
	char	**line; //girilen komut satırını 2 boyutlu dizede tutuyorum
	int		word_count; //argüman uzunluğunu tutuyorum
	int		i; //yardımcı fonk olarak kullanıyorum, forklar araya girerse kaldırılmak zorunda
	char	*path; //anlık dizi konumunu tutar.

}t_main;

//ft_strjoin.c
char	*ft_strjoin(const char *s1, const char *s2);

//ft_split.c
char	**ft_split(const char *s, char c);

//minishell.c
int		ft_strlen(const char *str);
int		main();

#endif