/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:40:24 by akaraca           #+#    #+#             */
/*   Updated: 2022/10/27 12:29:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h> /*
	write()		-> System call used to write data from the buffer
		ssize_t	write(int fd, const void *buf, size_t count);
https://man7.org/linux/man-pages/man2/write.2.html
	read()		-> Read from a file descriptor
		ssize_t read(int fd, void *buf, size_t count);
https://man7.org/linux/man-pages/man2/read.2.html
	fork()		-> Create thread from process
		pid_t fork(void);
https://man7.org/linux/man-pages/man2/fork.2.html
	access()	-> Check accessibility of a file
		int access(const char *pathname, int mode);
https://man7.org/linux/man-pages/man2/faccessat.2.html
	getcwd()	-> Get current working directory
		char *getcwd(char *buf, size_t size);
https://www.ibm.com/docs/en/i/7.4?topic=ssw_ibm_i_74/apis/getcwd.htm
	chdir()		-> Change working directory
		int	chdir(const char *path);
https://www.ibm.com/docs/en/i/7.4?topic=ssw_ibm_i_74/apis/chdir.htm
	unlink()	-> Delete a name and possibly the file it refers to
		int	unlink(const char *path);
https://shorturl.at/HKQ29
	execve()	-> Execute program
		int execve(const char *pathname, char *const argv[],
			char *const envp[]);
https://man7.org/linux/man-pages/man2/execve.2.html
	dup()		-> Duplicate a file descriptor(fd).
		int dup(int oldfd);
https://man7.org/linux/man-pages/man2/dup2.2.html
	dup2()		-> Duplicate a fd with
		int dup2(int oldfd, int newfd);
https://man7.org/linux/man-pages/man2/dup2.2.html
	pipe()		-> Create pipe
		int pipe(int pipefd[2]);
https://www.ibm.com/docs/en/i/7.5?topic=ssw_ibm_i_75/apis/pipe2.htm
	isatty()	-> Tests if there is an open file. If have open any file
			return 1, not have opened file return 0.
		int isatty(int fd);
https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-isatty-\
test-if-descriptor-represents-terminal
	ttyname()	-> Get name of associated terminal (tty) from file descriptor.
			It's working if isatty() is true.
		char *ttyname(int fildes);
https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-ttyname-\
get-name-terminal#rttty
	ttyslot()	-> Find the slot of the current user's terminal in some file.
		int ttyslot(void);
https://man7.org/linux/man-pages/man3/ttyslot.3.html
*/
# include <stdlib.h> /*
	free()		-> Deallocatig all allocated memory
		void free(void *ptr);
https://www.ibm.com/docs/en/i/7.5?topic=functions-free-release-storage-blocks
	exit()		-> Closing everything with atexit() and terminates program
		noreturn void exit(int status);
https://man7.org/linux/man-pages/man3/exit.3.html
	getenv()	-> Get an environment variable.
		char *getenv(const char *name);
https://www.ibm.com/docs/en/i/7.5?topic=ssw_ibm_i_75/apis/evgetenv.htm
https://linuxhint.com/getenv-function-usage/
*/
# include <stdio.h> /*
	printf()	-> A library function to send formatted output to the screen
		int printf(const char *restrict format, ...);
https://man7.org/linux/man-pages/man3/printf.3.html
	perror()	-> System error messages
		void perror(const char *string);
https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-perror\
-print-error-message
*/
# include <signal.h> /*
	signal()	-> Simplified software signal facilities.
		void (*signal(int sig, void (*func)(int)))(int);
https://linuxhint.com/signal_handlers_c_programming_language/
	sigaction()	-> 
		int sigaction(int signum, const struct sigaction *restrict act,
		struct sigaction *restrict oldact);
https://www.ibm.com/docs/en/zos/2.1.0?topic=functions-sigaction-\
examine-change-signal-action#rtsigac
	sigemptyset()	-> 
		int sigemptyset(sigset_t *set);
https://www.ibm.com/docs/en/zos/2.5.0?topic=functions-sigemptyset-\
initialize-signal-mask-exclude-all-signals
	sigaddset()	-> 
		int sigaddset(sigset_t *set, int signal);
https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-sigaddset-\
add-signal-signal-mask
	kill()		-> Send Signal to Process or Group of Processes. (PID).
		int kill(pid_t pid, int sig);
https://www.ibm.com/docs/en/i/7.2?topic=ssw_ibm_i_72/apis/sigkill.htm
*/
# include <stdint.h> /*
	Type	 	Name		Num_Bytes	Num_Bits	Integer_Range
	int8_t	 ->	char			1			8		-128 to 127,
	int16_t	 ->	short			2			16		-32768 to 32767,
	int32_t	 ->	int				4			32		-2147483648 to 2147483647,
	int64_t	 ->	long long		8			64	-9.223372e+18 to 9.223372e+18
	uint8_t	 ->	unsigned char	1			8			0 to 255,
	uint16_t ->	unsigned short	2			16			0 to 65535,
	uint32_t ->	unsigned int	4			32			0 to 4294967295,
	uint64_t ->	unsigned l_l 	8			64		0 to 18446744073709551615
*/
# include <string.h> /*
	malloc()	-> Allocating memory with NULL
		void *malloc(size_t size);
https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-malloc-\
reserve-storage-block
	strerror()	-> System error messages; Writing int errno's string value.
		char *strerror(int errnum);
https://www.ibm.com/docs/en/zos/2.5.0?topic=functions-strerror-\
get-pointer-runtime-error-message
*/
# include <fcntl.h> /* -File control-
	open()		-> Open or Create a file for reading or writing.
		int open(const char *path, int oflag, . . .);
https://www.ibm.com/docs/en/i/7.5?topic=ssw_ibm_i_75/apis/open.htm
	close()		-> Close File or Socket descriptor.
		int close(int fd);
https://www.ibm.com/docs/en/i/7.5?topic=ssw_ibm_i_75/apis/close.htm
*/
# include <dirent.h> /* -POSIX directory access functions-
	opendir()	-> Opens a directory so that it can be
 read with readdir() or __readdir2().
		DIR *opendir(const char *dirname);
https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-opendir-\
open-directory#rtoped
	readdir()	-> Returns a pointer to a dirent structure describing
 the next directory entry in the directory stream associated with dir.
		struct dirent *readdir(DIR *dir);
https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-readdir-\
read-entry-from-directory
	closedir()	-> Closes the directory indicated by dir.
 It frees the buffer that readdir() uses when reading the directory stream.
		int closedir(DIR *dir);
https://www.ibm.com/docs/en/zos/2.5.0?topic=functions-closedir-close-directory
*/
# include <termios.h> /* ?-General terminal line discipline-
	tcsetattr()	-> Set the parameters associated with the terminal
		int tcsetattr(int fildes, int optional_actions,
		const struct termios *termios_p);
https://www.ibm.com/docs/en/zos/2.5.0?topic=functions-tcsetattr-\
set-attributes-terminal
	tcgetattr()	-> Get the parameters associated with the terminal.
		int tcsetattr(int fd, int when, const struct termios *termptr);
https://www.ibm.com/docs/en/zos/2.5.0?topic=functions-tcgetattr-\
get-attributes-terminal#rttcga
*/
# include <curses.h> /* -Definitions for screen handling
 and optimization functions-
	tgetent()	-> Direct curses interface to the terminfo capability database,
		Routine loads the entry for name. It returns 1 on success, 0 if there
 is no such entry, and -1 if the terminfo database could not be found. The
 emulation ignores the buffer pointer bp.
	tgetflag()	-> Routine gets the boolean entry for id,
	tgetnum()	-> Routine gets the numeric entry for id,
	tgetstr()	-> Routine returns the string entry for id. 
		Use tputs() to output the returned string,
	tgoto()		-> Routine instantiates the parameters
 into the given capability.
		The output from this routine is to be passed to tputs(),
	tputs()		-> Routine is described on the curs_terminfo() manual page. 
	 It can retrieve capabilities by either termcap or terminfo name.
		int fputs(const char *string, FILE *stream);
https://www.ibm.com/docs/en/i/7.5?topic=functions-fputs-write-string#fputs
*/
# include <sys/wait.h> /*
	wait()		-> 
	waitpid()	->
	wait3()		->
	wait4()		->
*/
# include <sys/stat.h> /*
	stat()		-> Get file status,
	lstat()		-> Get file status,
	fstat()		-> Get file status
*/
# include <sys/ioctl.h> /*
	ioctl()		-> Control device.
*/
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
# include <errno.h> /* 
	errno;
*/
# include "../libraries/libft/includes/libft.h"
# include "colors.h" /* 🟥 🟩 🟦
	BLACK	"\033[0;30m"	B_RED		"\033[1;31m"
	RED		"\033[0;31m"	B_GREEN		"\033[1;32m"
	GREEN	"\033[0;32m"	B_YELLOW	"\033[1;33m"
	YELLOW	"\033[0;33m"	B_BLUE		"\033[1;34m"
	BLUE	"\033[0;34m"	B_CYAN		"\033[1;36m"
	PURPLE	"\033[0;35m"	B_RESET		"\033[1m"
	CYAN	"\033[0;36m"
	WHITE	"\033[0;37m"
	END		"\033[m"
	RESET	"\033[0m"
*/

# define CMD_CLEAR	"\e[1;1H\e[2J"

/*
terminal isminin basina/sonuna renk kodlarini eklersek yazilar ust uste biniyor
*/
# define T_NAME				"$୯> "
# define SHELLNAME			"minishell"

# define ERROR				-1
# define WHITESPACES		" \t\n"
# define QUOTE_MARKS		"\'\""

# define TOK_TEXT			1
# define TOK_S_QUOTE		2
# define TOK_D_QUOTE		4
# define TOK_REDIR_FILE		8
# define TOK_CONNECTED		16
# define TOK_PIPE			64
# define TOK_REDIR			512
# define TOK_HEREDOC		1024

# define ERR_SYNTAX			"syntax error"
# define ERR_SYNTAX_EXIT	2

# define ERR_UNO_BRACKET	"unopened brackets"
# define ERR_UNC_BRACKET	"unclosed brackets"
# define ERR_EMPTY_BRACKET	"empty brackets"
# define ERR_REDIR			"invalid redirection"
# define ERR_QUOTE			"unclosed quotation mark"
# define ERR_LIST			"incomplete command list"
# define ERR_MISS_OP		"missing operator"
# define ERR_PIPE			"incomplete pipe"

# define READ_END			0
# define WRITE_END			1

/* ************************************************************************** */
/* STRUCT DEFINES AREA													  	  */
/* ************************************************************************** */

typedef struct s_base	t_base;
typedef struct s_cmd	t_cmd;

/**
 * @brief Function pointer'ini tutan struct.
 * 
 * @param name*: Function name.
 * @param func*(base*_and_cmd*): Function'un kendisini tutan function pointer.
 * 
 */
typedef struct s_commands
{
	char	*name;
	int		(*func)(t_base *base, t_cmd *cmd, int i);
}		t_commands;

/**
 * @brief readline()'den alinan 'input'u tokenlerine ayirip,
 *  lexerli halini tutuyor.
 * 
 * @param flag: Token tipi (INTEGER).
 * @param str*: Lexer'li hali.
 * @param next*: Struct list'inin sonraki isaretcisi.
 * @param prev*: Struct list'inin onceki isaretcisi.
 */
typedef struct s_lexer
{
	int				flag;
	char			*str;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}		t_lexer;

/**
 * @brief Lexer'leme isleminden sonraki command listesini tutuyor.
 * 
 * @param full_cmd**: 
 * @param full_path*:
 * @param infile
 * @param outfile
 * @param size
 * @param next*: Struct list'inin sonraki isaretcisi.
 */
typedef struct s_cmd
{
	char			**full_cmd;
	char			**redirect;
	int				infile;
	int				outfile;
	int				red_size;
	int				size;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}		t_cmd;

/**
 * @brief Environment'lerimizi tutan struct.
 * 
 * NOTE: Env'nin sadece bir satirini tutuyor. 
 * 
 * @param data**: Environment'in; '='gordugunde
 *  sol ve sag kismi olarak ayriliyor,
 *  data[0]'da ETC=
 *  data[1]'de    =value		olarak tutuluyor.
 *  ETC:
 * 		PWD=/Users/gsever	-> data[0]=data[1]; -> "USER", "/Users/gsever"
 * @param is_env_equal: cmd_export icin, eger ayni env'den bir/birkac tane
 *  varsa false donecek. Eger ayni isimde env varsa true donecek.
 * @param next*: Struct list'inin sonraki isaretcisi.
 * @param prev*: Struct list'inin onceki isaretcisi. 
 * 
 */
typedef struct s_env
{
	char			**data;
	bool			is_env_equal;
	struct s_env	*next;
	struct s_env	*prev;
}		t_env;

/**
 * @brief Main structure.
 * 
 * @param mem_1*
 * @param mem_2*
 * @param fd_i
 * @param cmd_count
 * @param pid*
 * @param fd**
 * @param old_token*
 * @param input_line*: readline()'dan okunan input.
 * @param env_path**: Env'nin icindeki 'PATH' -> char **'la ':' olan kisimlari
 *  ayrilmis bir sekilde tutuyor.
 *  ETC:
 * 	PATH=/goinfre/gsever/brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:
 * 		env_path[0]:	/goinfre/gsever/brew/bin:
 * 		env_path[1]:			  /usr/local/bin:
 * 		env_path[2]:					/usr/bin:
 * 		env_path[3]:						/bin:
 * 		env_path[4]:				   /usr/sbin:
 * 		env_path[5]:					   /sbin:
 * @param env*: Environment'lerimizi tutan struct.
 * @param lexer*: Input'tan 'Token'leri alarak lexer'ledigimiz struct.
 * @param cmd*: Lexer'lenen 'token'leri integer command turune donusturuyor.
 * @param commands[8]: Bizden istenilen komutlari tutan struct.
 */
typedef struct s_base
{
	int			heredoc_status;
	char		**env_chr;
	int			err;
	char		*mem_1;
	char		*mem_2;
	int			fd_i;
	int			cmd_count;
	pid_t		*pid;
	int			**fd;
	char		*old_token;
	char		*input_line;
	char		**env_path;
	t_env		*env;
	t_lexer		*lexer;
	t_cmd		*cmd;
	t_commands	commands[8];
}		t_base;

/* ************************************************************************** */
/* FUNCTION PROTOTYPES														  */
/* ************************************************************************** */

// cmd_cd.c
int		cmd_cd(t_base *base, t_cmd *cmd, int i);

// cmd_echo.c
void	cmd_echo_print(t_cmd *cmd, int i);
int		cmd_echo(t_base *base, t_cmd *cmd, int i);

// cmd_env.c
int		cmd_env(t_base *base, t_cmd *cmd, int i);

// cmd_exit.c
int		cmd_exit(t_base *base, t_cmd *cmd, int i);

// cmd_export.c
int		cmd_export_add(t_base *base, t_cmd *cmd, int i);
void	cmd_export_print(t_base *base, t_cmd *cmd, int i);
int		cmd_export(t_base *base, t_cmd *cmd, int i);

// cmd_pwd.c
int		cmd_pwd(t_base *base, t_cmd *cmd, int i);

// cmd_set_fd.c
int		set_fd(int oldfd, char *path, int *flags);
char	*get_heredoc_str(char *limit);
int		set_heredoc(char *limit);
void	cmd_set_fd(t_lexer *tmp, t_cmd **new);

// cmd_unset.c
int		cmd_unset(t_base *base, t_cmd *cmd, int i);

// cmd.c
t_lexer	*cmd_node_create(t_cmd **new, t_lexer *last, int i, int l);
t_lexer	*cmd_create(t_cmd **lst, t_lexer *last);
void	cmd(t_base *base);

// command.c
int		cmd_other(t_base *base, t_cmd *cmd, char **cmd_array);
int		command_find_arr(t_base *base, t_cmd *cmd, char **cmd_array);
int		command_exec(t_base *base, t_cmd *cmd);

// debugging.c
void	debug_print_cmd(t_base *base, char *env_var, char *value);
void	debug_print_str(t_base *base, char *env_var, char *value);

// error.c
int		print_error(char *s1, char *s2, char *s3, char *message);
int		print_error_errno(char *s1, char *s2, char *s3);
int		exit_status(int err, bool status);

// fork.c
int		fork_start(t_base *base);
int		fork_init(t_base *base);

// free.c
void	free_env(t_env **env);
void	free_lexer(t_lexer **lexer);
void	free_cmd(t_cmd **cmd);
void	free_all(t_base *base);

// history.c
int		history_empty_check(char *input_line);

// init.c
void	commands_init(t_base *base);

// lexer_env_expand.c
int		is_it_expand(t_base *base, int status);
char	*env_expand_next_next(t_base *base, char *token, int *i, char *new);
char	*env_expand_next(t_base *base, char *token, int *i, char *new);
char	*env_expand(t_base *base, char *token, int i, int l);

// lexer_pipe.c
int		lexer_pipe(t_base *base, char *str, int *i);

// lexer_qutoe.c
int		lexer_quote(t_base *base, char *str, int *i);

// lexer_redir.c
int		lexer_redir(t_base *base, char *str, int *i);

// lexer_syntax.c
int		lexer_syntax(t_lexer *lexer);

// lexer_text.c
int		lexer_text(t_base *base, char *str, int *i);

// lexer.c
int		lexer(t_base *base, char *str);

// main.c
int		set_arg(t_base *base, char **environ);
int		main(int argc, char **argv, char **envp);

// minishell.c
void	minishell(t_base *base);

// signal.c
int		termios_change(bool echo_ctrl_character);
void	action_execve(int sig);
void	action_cat(int sig);
void	action_heredoc(int sig);
void	action(int sig);

// utils_cmd_two.c
t_lexer	*cmd_node_create(t_cmd **new, t_lexer *last, int i, int l);
t_lexer	*cmd_create(t_cmd **lst, t_lexer *last);
t_cmd	*cmd_lstlast(t_cmd *cmd);

// utils_cmd.c
void	cmd_set_me_fd_last_out(t_cmd *cmd, int *last_out);
void	close_cmd_fd(t_cmd *cmd);
int		cmd_count(t_cmd *cmd);
char	*str_add(char *tmp, char *str);
void	cmd_lstadd_back(t_cmd **lst, t_cmd *new);

// utils_command.c
char	*ft_path(char **path, char *cmd_name);
int		file_or_dir_search(char *str, int flag);
int		search_and_launch(char **cmd_array);

// utils_env.c
int		env_strlen(t_env *env);
char	*env_data(t_env *tmp);
char	**env_be_char(t_env *env);
bool	env_is_have(t_base *base, char *env_var, char *value);
void	set_env(t_base *base, char *env_name, char *new_str);
char	*env_findret(t_base *base, char *env_name);
char	*find_chr_ret_str(char *str, char c, bool status);
int		env_size(char *src);
char	**env_split(char *src);
int		env_struct(t_base *base, char *new_arg);
char	*env_findret_no_dup(t_base *base, char *env_name);

// utils_export.c
int		export_dot_slash_check(char *str);
int		export_arg_check(char **str);
int		export_same_check(t_base *base, char *str);
int		export_lstsize(t_env *lst);
char	*export_find_max_str(t_base *base);
char	*export_find_min_str(t_base *base);

// utils_fork.c
void	ft_wait(t_base *base);
void	fd_close(t_base *base);
void	fork_dup(t_base *base, int i, t_cmd *cmd);

// utils_free.c
void	free_fork_inits(t_base *base, int **fd);
void	free_pp_str(char **line);

// utils_func.c
char	*ft_chrjoin(char *s1, char c);
int		ft_strncmp_edited(const char *s1, const char *s2, size_t n);
int		ft_strcmp_edited(char *s1, char *s2);

// utils_lexer.c
t_lexer	*token_create(t_base *base, char *str, int type);
int		other_lenght(char *str);
void	node_merge(t_lexer **lexer, char *token, char *str, int *i);
t_lexer	*lexer_lstlast(t_lexer *lexer);
int		lexer_type(t_lexer *last, int type);

#endif
