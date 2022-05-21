/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:45:12 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 18:18:58 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 3

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
int					get_next_line(int const fd, char **line);
char				*ft_itoa_base(int value, int base);
int					ft_power(int nb, int power);
void				ft_swap(int *a, int *b);
int					*ft_range(int min, int max);
void				ft_putchar(int c);
unsigned int		ft_abs(int n);
void				ft_puttab_fd(char **tab, int nx, int fd);
void				ft_putchar_fd(char c, int fd);
void				*ft_memset(void *b, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, void *src, size_t n);
void				*ft_memccpy(void *dst, void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t len);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_bzero(void *b, size_t len);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strnstr(const char *str, char *to_find, size_t len);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncat(char *dest, char *src, int nb);
size_t				ft_strlcat(char *dest, char *src, unsigned int size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcat(char *dest, const char *src);
void				ft_putstr(char *str);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putendl(const char *str);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_toupper(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isblank(int c);
char				*ft_strcapitalize(char *str);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
int					ft_atoi(char *str);
char				*ft_itoa(int n);
size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *src);
char				*ft_strndup(const char *src, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void(*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
#endif
