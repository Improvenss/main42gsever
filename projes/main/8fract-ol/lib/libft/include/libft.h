/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:51:02 by tjensen           #+#    #+#             */
/*   Updated: 2021/09/24 10:38:59 by tjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/types.h>

# include "../modules/ft_printf/include/ft_printf.h"
# include "../modules/get_next_line/include/get_next_line_bonus.h"

/* is & to */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/* list */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
math
*/

/* BASES */
# define BASE2 "01"
# define BASE4 "0123"
# define BASE6 "012345"
# define BASE8 "01234567"
# define BASE10 "0123456789"
# define BASE12_U "0123456789AB"
# define BASE12_L "0123456789ab"
# define BASE14_U "0123456789ABCD"
# define BASE14_L "0123456789abcd"
# define BASE16_U "0123456789ABCDEF"
# define BASE16_L "0123456789abcdef"

int		ft_fibonacci(int index);
int		ft_find_next_prime(int nb);
int		ft_is_prime(int nb);
int		ft_iterative_factorial(int nb);
int		ft_iterative_power(int nb, int power);
int		ft_recursive_factorial(int nb);
int		ft_recursive_power(int nb, int power);
int		ft_sqrt(int nb);
int		ft_get_numlen(long n);
int		ft_get_numlen_base(long n, u_int base);
int		ft_get_unumlen(u_long nb);
int		ft_get_unumlen_base(u_long n, u_int base);
u_long	ft_abs(long nb);

/* memory */
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);

/* put */
int		ft_putchar_fd(char c, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(long n, int fd);
int		ft_putunbr_fd(u_long n, int fd);
int		ft_putnbr_base_fd(long num, char *base, int fd);
int		ft_putunbr_base_fd(u_long num, char *base, int fd);
int		ft_putstr_fd(char *s, int fd);

/* string */
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
long	ft_atol(const char *nptr);
double	ft_atod(const char *nptr);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_ltoa(long n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

#endif
