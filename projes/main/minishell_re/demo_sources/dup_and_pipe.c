#include  <fcntl.h>                              //
#include  <stdio.h>                              //
#include  <stdlib.h>                             //
#include  <string.h>                             //
#include  <sys/types.h>                          //
#include  <sys/wait.h>                           //
#include  <sys/stat.h>                           //
#include  <termios.h>                            //
#include  <unistd.h> 


static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		count++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static char	*stringf(const char *s, char c)
{
	char	*temp;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(const char *s, char c)
{
	char	**temp;
	int		wordc;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	wordc = ft_wordcount(s, c);
	temp = (char **)malloc(sizeof(char *) * (wordc + 1));
	if (!temp)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			temp[i] = stringf(s, c);
			i++;
		}
		while (*s && *s != c)
		s++;
	}
	temp[i] = NULL;
	return (temp);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*temp;

	i = 0;
	k = 0;
	temp = NULL;
	if (!s1 || !s2)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + \
				ft_strlen(s2) + 1));
	if (!temp)
		return (NULL);
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		temp[k + i] = s2[k];
		k++;
	}
	temp[k + i] = '\0';
	return (temp);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	ft_strncmp_edited(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1 && (*s1 != '\0') && (*s1 == *s2) && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0 && (s1[n] == ' ' || s1[n] == '\0')) // "(s1[n] == ' ' || s1[n] == '\0')" cd .. <enter> durumu, cd.. <enter> şeklinde kullanılmasını engellemek için konuldu.
		return (1);
	return (0);
}


/*
// ./a.out ls | wc -l
// ls: /bin/ls
// wc: /usr/bin/wc
// girdi:  "./a.out ls -la | wc -l <enter>"
int main(int argc, char **argv)
{
	extern char **environ;
	int fd[2];
	char *s1 = "wc -l";
	char *s2 = "ls -la";
	pipe(fd);

	int pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/bin/ls", ft_split(s2, ' '), environ);
	}

	int pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/wc", ft_split(s1, ' '), environ);
	}

	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}*/


char *ft_delete_space(char *str)
{
	char *tmp;
	int i;
	int l;
	int k;

	i = 0;
	k = 0;
	l = ft_strlen(str) - 1;
	while (str[i] == 32 && str[i])
		i++;
	while (str[l] == 32 && str[l])
		l--;
	tmp = (char *)malloc(sizeof(char) * (l - i));
	if (!tmp)
		return (NULL);
	while (str[i] && i <= l)
	{
		while (str[i - 1] == 32 && str[i] == 32)
			i++;
		tmp[k] = str[i];
		k++;
		i++;
	}
	tmp[k] = '\0';
	free(str);
	return (tmp);
}

/*
// ./a.out "ls | wc -l | wc -c"
// ls: /bin/ls
// wc: /usr/bin/wc
// girdi:  "./a.out "ls -la | wc -l | wc -c" <enter>"
int main(int argc, char **argv)
{
	extern char **environ;
	char **tmp;
	char *s1;
	char *s2;
	int	pipe_count;

	argv++;
	argc++;
	printf("girdi: %s\n\n", argv[0]);
	int i = 0;
	pipe_count = 0;
	tmp = ft_split(argv[0], '|'); //komut bloklarını tutuyor.
	while (tmp[i])
	{
		tmp[i] = ft_delete_space(tmp[i]);
		printf("--> ^%s^\n", tmp[i]);
		i++;
	}
	printf("split_count: %d\n\n", i);
	int fd[2];
	int pid1;
	int pid2;
	pipe(fd);

	pid1 = fork();
	if (pid1 == 0)
	{
		if (i > 1)
			dup2(fd[1], 1);
		else
			dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		execve("/bin/ls", ft_split(tmp[pipe_count], ' '), environ);
	}
	if (i == 1)
		waitpid(pid1, NULL, 0);


	if (i > 1 && pipe_count < i)
	{
		pipe_count++;
		pid2 = fork();
		if (pid2 == 0)
		{
			dup2(fd[0], 0);
			close(fd[0]);
			close(fd[1]);
			execve("/usr/bin/wc", ft_split(tmp[pipe_count], ' '), environ);
		}
	}
	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}*/


/*
// ./a.out "ls | wc -l | wc -c"
// ls: /bin/ls
// wc: /usr/bin/wc
// girdi:  "./a.out "ls -la | wc -l | wc -c" <enter>"
int main(int argc, char **argv)
{
	extern char **environ;
	char **tmp;
	char *s1;
	char *s2;
	int	pipe_count;

	argv++;
	argc++;
	printf("girdi: %s\n\n", argv[0]);
	int i = 0;
	pipe_count = 0;
	tmp = ft_split(argv[0], '|'); //komut bloklarını tutuyor.
	while (tmp[i])
	{
		tmp[i] = ft_delete_space(tmp[i]);
		printf("--> ^%s^\n", tmp[i]);
		i++;
	}
	printf("split_count: %d\n\n", i);

	int fd[2];
	int pid1;
	int pid2;
	pipe(fd);

	while (pipe_count < i)
	{
		pid1 = fork();
		if (pid1 == 0)
		{
			if (pipe_count + 1 == i)
				dup2(fd[0], 0);
			else if (i > 1)
				dup2(fd[1], 1);
			close(fd[0]);
			close(fd[1]);
			execve("/bin/ls", ft_split(tmp[pipe_count], ' '), environ);
		}
		if (i == 1)
			waitpid(pid1, NULL, 0);
		if (i > 1 && pipe_count < i)
		{
			pipe_count++;
			pid2 = fork();
			if (pid2 == 0)
			{
				if (pipe_count + 1 == i)
					dup2(fd[0], 0);
				else if (i > 2)
					dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
				execve("/usr/bin/wc", ft_split(tmp[pipe_count], ' '), environ);
			}
		}
		if (pipe_count + 1 == i)
		{
			close(fd[0]);
			close(fd[1]);

			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
		pipe_count++;
	}
	return (0);
}*/



/*
// ./a.out "ls | wc -l | wc -c"
// ls: /bin/ls
// wc: /usr/bin/wc
// girdi:  "./a.out "ls -la | wc -l | wc -c" <enter>"
int main(int argc, char **argv)
{
	extern char **environ;
	char **tmp;
	char *s1;
	char *s2;
	int	pipe_count;

	argv++;
	argc++;
	printf("girdi: %s\n\n", argv[0]);
	int i = 0;
	pipe_count = 0;
	tmp = ft_split(argv[0], '|'); //komut bloklarını tutuyor.
	while (tmp[i])
	{
		tmp[i] = ft_delete_space(tmp[i]);
		printf("--> ^%s^\n", tmp[i]);
		i++;
	}
	printf("split_count: %d\n\n", i);

	int fd[2];
	int pid1;
	int pid2;
	pipe(fd);

	while (pipe_count < i)
	{
		pid1 = fork();
		if (pid1 == 0)
		{
			if (pipe_count + 1 == i)
				dup2(fd[0], 0);
			else if (i > 1)
				dup2(fd[1], 1);
			close(fd[0]);
			close(fd[1]);
			execve("/bin/ls", ft_split(tmp[pipe_count], ' '), environ);
		}
		if (i == 1)
			waitpid(pid1, NULL, 0);
		if (i > 1 && pipe_count + 1 < i)
		{
			pipe_count++;
			pid2 = fork();
			if (pid2 == 0)
			{
				if (pipe_count + 1 == i)
					dup2(fd[0], 0);
				else if (i > 2)
					dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
				execve("/usr/bin/wc", ft_split(tmp[pipe_count], ' '), environ);
			}
		}
		close(fd[0]);
		close(fd[1]);
		if (pipe_count + 1 == i)
		{
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
		pipe_count++;
	}
	return (0);
}*/


/*
// ./a.out "ls | wc -l | wc -c"
// ls: /bin/ls
// wc: /usr/bin/wc
// girdi:  "./a.out "ls -la | wc -l | wc -c" <enter>"
int main(int argc, char **argv)
{
	extern char **environ;
	char **tmp;
	char *s1;
	char *s2;
	int	pipe_count;

	argv++;
	argc++;
	printf("girdi: %s\n\n", argv[0]);
	int i = 0;
	pipe_count = 0;
	tmp = ft_split(argv[0], '|'); //komut bloklarını tutuyor.
	while (tmp[i])
	{
		tmp[i] = ft_delete_space(tmp[i]);
		printf("--> ^%s^\n", tmp[i]);
		i++;
	}
	printf("split_count: %d\n\n", i);

	int fd[2][2];
	int pid1;
	int pid2;
	int pid3;
	pipe(fd[0]);
	pipe(fd[1]);

	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fd[0][1], 1);
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		execve("/bin/ls", ft_split(tmp[pipe_count], ' '), environ);
	}

	pipe_count++;
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0][0], 0);
		dup2(fd[1][1], 1);
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		execve("/usr/bin/wc", ft_split(tmp[pipe_count], ' '), environ);
	}

	pipe_count++;
	pid3 = fork();
	if (pid3 == 0)
	{
		dup2(fd[1][0], 0);
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		execve("/usr/bin/wc", ft_split(tmp[pipe_count], ' '), environ);
	}

	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[1][1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);

	return (0);
}*/

int main(int argc, char **argv)
{
	extern char **environ;
	char **tmp;
	char *s1;
	char *s2;
	int	pipe_count;

	argv++;
	argc++;
	printf("girdi: %s\n\n", argv[0]);
	int i = 0;
	pipe_count = 0;
	tmp = ft_split(argv[0], '|'); //komut bloklarını tutuyor.
	while (tmp[i])
	{
		tmp[i] = ft_delete_space(tmp[i]);
		printf("--> ^%s^\n", tmp[i]);
		i++;
	}
	printf("split_count: %d\n\n", i);

	int **fd;
	fd = (int **)malloc(sizeof(int*) * i - 1);
	fd[0] = (int *)malloc(sizeof(int) * 2);
	fd[1] = (int *)malloc(sizeof(int) * 2);

	int *pid;

	pid = (int *)malloc(sizeof(int) * i);
	pipe(fd[0]);
	pipe(fd[1]);

	pid[0] = fork();
	if (pid[0] == 0)
	{
		dup2(fd[0][1], 1); // tek bir fork var ise yazdırmak istiyorsak dup2(fd[0][0], 0); kullanılmaldıır.
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		execve("/bin/ls", ft_split(tmp[pipe_count], ' '), environ);
	}

	pipe_count++;
	pid[1] = fork();
	if (pid[1] == 0)
	{
		dup2(fd[0][0], 0);
		dup2(fd[1][1], 1);
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		execve("/usr/bin/wc", ft_split(tmp[pipe_count], ' '), environ);
	}

	pipe_count++;
	pid[2] = fork();
	if (pid[2] == 0)
	{
		dup2(fd[1][0], 0);
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		execve("/usr/bin/wc", ft_split(tmp[pipe_count], ' '), environ);
	}

	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[1][1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	waitpid(pid[2], NULL, 0);

	return (0);
}