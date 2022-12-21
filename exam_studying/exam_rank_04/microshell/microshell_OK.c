#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int	err(char *s1, char *s2)
{
	while (*s1)
		write(2, s1++, 1);
	if (s2)
		while (*s2)
			write(2, s2++, 1);
	write(2, "\n", 1);
	return (1);
}

int	exec_cmd(char **argv, char **envp, int i, int tmp_fd)
{
	argv[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(argv[0], argv, envp);
	return (err("error: cannot execute ", argv[0]));
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	int	i;
	int	tmp_fd;
	int	fd[2];

	i = 0;
	tmp_fd = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (!strcmp(argv[0], "cd"))
		{
			if (i != 2)
				err("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]))
				err("error: cd: cannot change directory to ", argv[1]);
		}
		else if (i != 0 && (argv[i] == NULL || !strcmp(argv[i], ";")))
		{
			// err(";'e girdik yarraa", NULL);
			if (fork() == 0)
			{
				if (exec_cmd(argv, envp, i, tmp_fd))
					return (1);
			}
			else
			{
				close(tmp_fd);
				waitpid(-1, NULL, WUNTRACED);
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && !strcmp(argv[i], "|"))
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
	}
	close(tmp_fd);
	return (0);
}