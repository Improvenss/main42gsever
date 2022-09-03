/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraca <akaraca@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:57:07 by akaraca           #+#    #+#             */
/*   Updated: 2022/09/02 18:58:49 by akaraca          ###   ########.fr       */
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
# include <sys/wait.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>

# define BLACK "\e[0;30m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define PURPLE "\e[0;35m"
# define CYAN "\e[0;36m"
# define WHITE "\e[0;37m"
# define FINISH "\e[m"
//# define COMMAND_SIGN "\e[0;32m🅼 🅸 🅽 🅸 🆂 🅷 🅴 🅻 🅻 $\e[m" // readline(COMMAND_SIGN); şeklinde kullanılıyor.
//# define COMMAND_SIGN "\e[0;32m$\e[m "

typedef struct s_env // env yapısını içerecek 
{
	char	**data; //data[0] -> PWD,OLDPWD,HOME,_ .... data[1] -> /Users/akaraca/Desktop/minishell/sources, /Users/akaraca/Desktop/minishell, /Users/akaraca ...
	struct s_env *next;
	struct s_env *prev;
}t_env;

typedef struct s_main
{
	const char	*cmd; //realine(), geri dönüş değerini tutuyor.
	char		**line; //girilen komut satırını 2 boyutlu dizede tutuyorum // 1.indexten sonrasında space(32) karakteri bulunuyor, son index hariç
	char		**const_line; //girilen komut satırını 2 boyutlu dizede tutuyorum, ekstra bir karakter girdisi yok.
	char		**tmp_environ; // "extern char	**environ;" hafızaya alıyorum.
	int			i; //yardımcı fonk olarak kullanıyorum, forklar araya girerse kaldırılmak zorunda
	char		*path; //anlık dizi konumunu tutar.
	char		*old_path; // yapılan cd komutuna göre bir önceki dizini tutar.
	char		*command_path; // ls, clear, man ... vb komutların "/bin/..." dizinin eşitliğini tutuyor.
	t_env		*env; //extern char **environ; 2 boyutlu dizisi üzerinde düzenleme yapabilmek için list yapısı oluşturduk.
	t_env		*env_export;
}t_main;

//minishell.c
int		main(void);

#endif