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

char	*ft_path(char **path, char *tmp)
{
	char **str = ft_split(tmp, ' '); //ls -la'nın ls kısmı lazım.
	char *dir1;
	char *dir2;
	int i = -1;
	while (path[++i])
	{
		dir2 = ft_strjoin("/", str[0]);
		dir1 = ft_strjoin(path[i], dir2);
		free(dir2);
		if (access(dir1, 0) == 0)
		{
			return (dir1);
		}
		free(dir1);
	}
	return (NULL);
}

// gcc multiple_pipe.c && ./a.out "ls |ls | ls | ls | ls | ls | ls | ls"
int main(int argc, char **argv)
{
	extern char **environ;
	int x = 0;
	char *str;
	while (environ[x])
	{
		if (ft_strncmp_edited("PATH",environ[x],4))
			str = ft_strdup(&environ[x][5]); //= 'den sonrasını atıyorum
		x++;
	}
	//printf("-->  %s\n", str);
	char **path = ft_split(str, ':');


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
	int l = 0;
	fd = (int **)malloc(sizeof(int*) * i);
	if (i == 1)
	{
		printf("Tekli fd girdisi\n");
		fd[0] = (int *)malloc(sizeof(int) * 2);
	}
	while (l < i - 1)
	{
		printf("-fd l : %d-\n", l);
		fd[l++] = (int *)malloc(sizeof(int) * 2);
	}

	int *pid;
	pid = (int *)malloc(sizeof(int) * i);

	l = 0;
	if (i == 1)
	{
		printf("Tekli pipe girdisi\n");
		pipe(fd[0]);
	}
	while (l < i - 1)
	{
		printf("-pipe l: %d-\n", l);
		pipe(fd[l++]);
	}

	l = 0;
	while (l < i)
	{
		pid[l] = fork();
		if (pid[l] == 0)
		{
			//printf("----l: %d---\n", l);
			if (i == 1)
				dup2(fd[l][0], 0); // pipe olmadan yapılan fonk çalışması için.
			else if (l == 0)
			{
				printf("Başlangıç l: %d\n", l); // en baştaki komut bloğu.
				dup2(fd[l][1], 1);
			}
			else if (l + 1 != i)
			{
				printf("Orta l: %d\n", l);
				dup2(fd[l - 1][0], 0);
				dup2(fd[l][1], 1);
			}
			else if (l + 1 == i)
			{
				printf("Son l: %d\n", l);
				dup2(fd[l - 1][0], 0);
			}
			int k = 0;
			while (k < i - 1)
			{
				close(fd[k][0]);
				close(fd[k][1]);
				k++;
			}
			//execlp("ls", "ls", NULL);
			//execve("/bin/ls", ft_split(tmp[l], ' '), environ);
			execve(ft_path(path, tmp[l]), ft_split(tmp[l], ' '), environ);
		}
		l++;
	}
	int k = 0;
	while (k < i - 1)
	{
		close(fd[k][0]);
		close(fd[k][1]);
		k++;
	}
	k = 0;
	while (pid[k] < i)
		waitpid(pid[k++], NULL, 0);
	return (0);
}