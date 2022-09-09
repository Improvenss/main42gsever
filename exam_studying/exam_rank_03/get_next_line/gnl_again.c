#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int		rd;
	char 	c;
	if ((rd = read(fd, &c, 1) == 0))
		return (NULL);
	char	*line = malloc(sizeof(10000000));
	char	*word = line;
	*line++ = c;
	while ((rd = read(fd, &c, 1) > 0) && c != '\n')
		*line++ = c;
	if (c == '\n')
		*line++ = '\n';
	*line = '\0';
	return (word);
}

#include <fcntl.h>
#include <stdio.h>
int	main()
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf ("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
