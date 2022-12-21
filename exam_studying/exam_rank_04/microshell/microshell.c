#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// #ifdef TEST_SH
// # define TEST		1
// #else
// # define TEST		0
// #endif

int	ft_putstr_fd(char *str, char *arg, int fd)
{
	while (*str)
		write(fd, str++, 1);
	if (arg)
		while(*arg)
			write(fd, arg++, 1);
	write(fd, "\n", 1);
	return (-1);
}

int	exec_cmd(char **argv, char **envp, int i, int tmp_fd)
{
	argv[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(argv[0], argv, envp);//execve kendisi exit(); attigi icin fork()'la olusturulan child direkt cikiyor. error'a girmiyor.
	return (ft_putstr_fd("error: cannot execute ", argv[0], 2));
}

// #include <stdio.h>
int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	int	i;
	int	fd[2];
	int	tmp_fd;

	tmp_fd = dup(STDIN_FILENO);
	i = 0;
	while (argv[i] && argv[++i])
	{
		argv += i;
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(*argv, "cd") == 0)
		{
			if (i != 2)
				ft_putstr_fd("error: cd: bad arguments", NULL, 2);
			else if (chdir(argv[1]) != 0)
				ft_putstr_fd("error: cd: cannot change directory to ", argv[1], 2);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))// stdout'a execve'yle calistiriyoruz
		{
			if (fork() == 0)
			{
				if (exec_cmd(argv, envp, i, tmp_fd) == -1)
					return (1);
			}
			else
			{
				close(tmp_fd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)// pipe varsa
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (exec_cmd(argv, envp, i, tmp_fd))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
		close(tmp_fd);
		// if (TEST)
		// 	while (1);
	}
	return (0);
}