/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:57:07 by akaraca           #+#    #+#             */
/*   Updated: 2022/08/26 19:41:19 by akaraca          ###   ########.fr       */
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
# define COMMAND_SIGN "\e[0;32m🅼 🅸 🅽 🅸 🆂 🅷 🅴 🅻 🅻 $\e[m "

typedef struct s_main
{
	char		**line; //girilen komut satırını 2 boyutlu dizede tutuyorum
	int			word_count; //argüman uzunluğunu tutuyorum
	int			i; //yardımcı fonk olarak kullanıyorum, forklar araya girerse kaldırılmak zorunda
	char		*path; //anlık dizi konumunu tutar.
	char		*old_path; // yapılan cd komutuna göre bir önceki dizini tutar.
}t_main;

//ft_strjoin.c
char	*ft_strjoin(const char *s1, const char *s2);

//ft_split.c
char	**ft_split(const char *s, char c);

//minishell.c
int		ft_strlen(const char *str);
int		main(void);

#endif