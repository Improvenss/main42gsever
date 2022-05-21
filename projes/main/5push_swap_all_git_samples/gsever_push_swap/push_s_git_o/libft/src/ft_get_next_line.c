/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_next_line.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/02 15:25:57 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 19:06:12 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_list	*find_fd(t_list **lst, int const fd)
{
	t_list		*newfd;

	newfd = *lst;
	while (newfd && fd != (int)(newfd->content_size))
		newfd = newfd->next;
	if (!newfd && fd >= 0)
	{
		newfd = ft_lstnew(NULL, 0);
		ft_lstadd(lst, newfd);
		newfd->content_size = (int)fd;
	}
	return (newfd);
}

static int		current_line(char **line, t_list **str, int flag)
{
	int		i;

	i = 0;
	while (((char*)((*str)->content))[i] &&
			((char*)((*str)->content))[i] != '\n')
		i++;
	*line = ft_strsub((*str)->content, 0, i);
	(*str)->content = (char*)ft_memmove((*str)->content,
			ft_strchr((*str)->content, '\n') + 1,
			ft_strlen(ft_strchr((*str)->content, '\n')));
	if (!flag)
		free((*str)->content);
	return (1);
}

static char		*strmerge(char *s1, char *s2)
{
	char	*str;

	str = s1;
	s1 = ft_strjoin(s1, s2);
	ft_strdel(&str);
	return (s1);
}

int				get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*lst;
	t_list			*cur;
	int				rd;

	if (read(fd, NULL, 0) == -1 || !line)
		return (-1);
	cur = find_fd(&lst, fd);
	if (ft_strlen(cur->content) > 0 && ft_strchr(cur->content, '\n'))
		return (current_line(line, &cur, 1));
	while ((rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd] = '\0';
		cur->content = !cur->content ? ft_strdup(buf)
			: strmerge(cur->content, buf);
		if (ft_strchr(cur->content, '\n'))
			return (current_line(line, &cur, 1));
	}
	if (ft_strlen(cur->content) > 0)
		return (current_line(line, &cur, 0));
	return (0);
}
