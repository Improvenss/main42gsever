/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:57:07 by akaraca           #+#    #+#             */
/*   Updated: 2022/09/08 17:04:20 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libraries/libft/includes/libft.h"
# include <unistd.h> /*
	write()		-> System call used to write data from the buffer,
	read()		-> Read from a file descriptor,
	fork()		-> Create thread from process,
	access()	-> Check accessibility of a file,
	getcwd()	-> Get current working directory,
	chdir()		-> Change working directory,
	unlink()	-> Delete a name and possibly the file it refers to,
	execve()	-> Execute program,
	dup()		-> Duplicate a file descriptor(fd) -> int dup2(int oldfd);,
	dup2()		-> Duplicate a fd with -> int dup2(int oldfd, int newfd);,
	pipe()		-> Create pipe -> int pipe(int pipefd[2]);,
	isatty()	-> Tests if there is an open file. If have open any file
		return 1, not have opened file return 0. -> int isatty(int fd);,
	ttyname()	-> Get name of associated terminal (tty) from file descriptor.
		It's working if isatty() is true.
	ttyslot()	-> Find the slot of the current user's terminal in some file. */
# include <stdlib.h> /*
	free()		-> Deallocatig all allocated memory,
	exit()		-> Closing everything with atexit() and terminates program,
	getenv()	-> Get an environment variable. */
# include <stdio.h> /*
	printf()	-> A library function to send formatted output to the screen,
	perror()	-> System error messages -> void perror(const char *s);. */
# include <signal.h> /*
	signal()	-> 
	sigaction()	-> 
	sigemptyset()	-> 
	sigaddset()	-> 
	kill()		-> Close process from PID. */
# include <stdint.h> /*
	Type	 	Name		Num_Bytes	Num_Bits	Integer_Range
	int8_t	 ->	char			1			8		-128 to 127,
	int16_t	 ->	short			2			16		-32768 to 32767,
	int32_t	 ->	int				4			32		-2147483648 to 2147483647,
	int64_t	 ->	long long		8			64		-9.223372e+18 to 9.223372e+18
	uint8_t	 ->	unsigned char	1			8			0 to 255,
	uint16_t ->	unsigned short	2			16			0 to 65535,
	uint32_t ->	unsigned int	4			32			0 to 4294967295,
	uint64_t ->	unsigned l_l 	8			64		0 to 18446744073709551615 */
# include <string.h> /*
	malloc()	-> Allocating memory with NULL,
	strerror()	-> System error messages -> char *strerror(int errnum);,
	 */
# include <fcntl.h> /*
	open()		-> Open files and directories,
	close()		-> Delete a descriptor. */
# include <dirent.h> /*
	opendir()	-> Open a directory -> DIR *opendir(const char *name);,
	readdir()	-> Read a directory -> struct dirent *readdir(DIR *dirp);,
	closedir()	-> Close a directory -> int closedir(DIR *dirp);. */
# include <termios.h> /*
	tcsetattr()	-> Set the parameters associated with the terminal,
	tcgetattr()	-> Get the parameters associated with the terminal. */
# include <curses.h> /*
	tgetent()	-> Direct curses interface to the terminfo capability database,
		Routine loads the entry for name. It returns 1 on success, 0 if there 
		is no such entry, and -1 if the terminfo database could not be found. 
		The emulation ignores the buffer pointer bp.
	tgetflag()	-> Routine gets the boolean entry for id,
	tgetnum()	-> Routine gets the numeric entry for id,
	tgetstr()	-> Routine returns the string entry for id. 
		Use tputs() to output the returned string,
	tgoto()		-> Routine instantiates the parameters into the given capability. 
		The output from this routine is to be passed to tputs(),
	tputs()		-> Routine is described on the curs_terminfo() manual page. 
		It can retrieve capabilities by either termcap or terminfo name. */
# include <term.h> /*
	*/
# include <sys/wait.h> /*
	wait()		-> 
	waitpid()	->
	wait3()		->
	wait4()		->  */
# include <sys/stat.h> /*
	stat()		-> Get file status,
	lstat()		-> Get file status,
	fstat()		-> Get file status, */
# include <sys/ioctl.h> /*
	ioctl()		-> Control device. */
# include <readline/readline.h> /* 
	readline()	->
	rl_clear_history()	->
	rl_on_new_line()	->
	rl_replace_line()	->
	rl_redisplay()	->
 */
# include <readline/history.h> /*
	add_history()	-> 
	*/
# include <pthread.h> /*
	*/

//	COLORS --> 🟥 🟩 🟦
# define BLACK "\e[0;30m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define PURPLE "\e[0;35m"
# define CYAN "\e[0;36m"
# define WHITE "\e[0;37m"
# define X		"\033[m"
# define FINISH	"\e[m"
# define RESET	"\033[0m"
//# define COMMAND_SIGN "\e[0;32m🅼 🅸 🅽 🅸 🆂 🅷 🅴 🅻 🅻 $\e[m" // readline(COMMAND_SIGN); şeklinde kullanılıyor.
//# define COMMAND_SIGN "\e[0;32m$\e[m "

typedef struct s_env // env yapısını içerecek 
{
	char	**data; //data[0] -> PWD,OLDPWD,HOME,_ .... data[1] -> /Users/akaraca/Desktop/minishell/sources, /Users/akaraca/Desktop/minishell, /Users/akaraca ...
	struct s_env *next; //env listesinin bir sonraki argümanını işaret ediyor.
	struct s_env *prev; //env listesinden argüman silmek için kullandığım, bir önceki argümanı işaret eden işaretçi
}t_env;

typedef struct s_main
{
	const char	*cmd; //realine(), geri dönüş değerini tutuyor.
	char		**line; //girilen komut satırını 2 boyutlu dizede tutuyorum // 1.indexten sonrasında space(32) karakteri bulunuyor, son index hariç
	char		**const_line; //girilen komut satırını 2 boyutlu dizede tutuyorum, ekstra bir karakter girdisi yok.
	char		**environ; // "extern char	**environ;" hafızaya alıyorum.
	int			i; //yardımcı fonk olarak kullanıyorum, forklar araya girerse kaldırılmak zorunda
	char		*path; //anlık dizi konumunu tutar.
	char		*old_path; // yapılan cd komutuna göre bir önceki dizini tutar.
	char		*command_path; // ls, clear, man ... vb komutların "/bin/..." dizinin eşitliğini tutuyor.
	char		*launch_path; // dosya çalıştırmak için gereken, program adını içeren path uzantısı.
	char		**launch_argv; // çalıştırılmak istenen programın argüman içeriğini tutan 2 boyutlu dize.
	t_env		*env; //extern char **environ; 2 boyutlu dizisi üzerinde düzenleme yapabilmek için list yapısı oluşturduk.
}t_main;

int		main(void);

#endif