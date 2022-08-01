/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:43:24 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/15 19:25:44 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	int					chr_count;
	char				*buf;
	char				*tmp;
	static t_gnl_list	*t_list = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	chr_count = 1;
	while (!ft_strchr(ft_lst_foc(&t_list, fd)->rd_str, '\n') && chr_count > 0)
	{
		chr_count = read(fd, buf, BUFFER_SIZE);
		if (chr_count == -1)
			return (ft_gnl_free_all(buf, &t_list, fd));
		buf[chr_count] = '\0';
		tmp = ft_lst_foc(&t_list, fd)->rd_str;
		ft_lst_foc(&t_list, fd)->rd_str = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if ((ft_lst_foc(&t_list, fd)->rd_str)[0] != '\0')
		return (process_next_line(buf, &t_list, fd));
	return (ft_gnl_free_all(buf, &t_list, fd));
}

char	*process_next_line(char *buf, t_gnl_list **lst, int fd)
{
	int			chr_count;
	char		*stat;
	char		*nxt_ln;
	t_gnl_list	*item;

	item = ft_lst_foc(lst, fd);
	stat = item->rd_str;
	if (ft_strchr((stat), '\n'))
	{
		chr_count = ft_strchr(stat, '\n') + 1 - stat;
		nxt_ln = ft_substr(stat, 0, chr_count);
		item->rd_str = ft_substr(stat, chr_count, ft_strlen(stat) - chr_count);
		free(stat);
	}
	else
	{
		nxt_ln = ft_substr(stat, 0, ft_strlen(stat));
		ft_gnl_free_lst(lst, fd);
	}
	free(buf);
	return (nxt_ln);
}

t_gnl_list	*ft_gnl_lstnew(int fd)
{
	t_gnl_list	*new_lst_item;

	new_lst_item = malloc(sizeof(t_gnl_list));
	if (new_lst_item == NULL)
		return (NULL);
	new_lst_item->fd = fd;
	new_lst_item->rd_str = ft_substr("", 0, 0);
	new_lst_item->next = NULL;
	return (new_lst_item);
}

t_gnl_list	*ft_lst_foc(t_gnl_list **lst, int fd)
{
	t_gnl_list	*tmp;

	if (*lst == NULL)
	{
		*lst = ft_gnl_lstnew(fd);
		return (*lst);
	}
	if ((*lst)->fd == fd)
		return (*lst);
	tmp = (*lst);
	while (tmp->next != NULL && tmp->next->fd != fd)
		tmp = tmp->next;
	if (tmp->next == NULL)
		tmp->next = ft_gnl_lstnew(fd);
	return (tmp->next);
}

void	ft_gnl_free_lst(t_gnl_list **lst, int fd)
{
	t_gnl_list	*tmp;
	t_gnl_list	*to_free;

	if ((*lst)->next == NULL && (*lst)->fd == fd)
	{
		to_free = *lst;
		*lst = NULL;
	}
	else if ((*lst)->next != NULL && (*lst)->fd == fd)
	{
		to_free = *lst;
		*lst = (*lst)->next;
	}
	else
	{
		tmp = *lst;
		while (tmp->next != NULL && tmp->next->fd != fd)
			tmp = tmp->next;
		to_free = tmp->next;
		tmp->next = tmp->next->next;
	}
	free(to_free->rd_str);
	free(to_free);
}
