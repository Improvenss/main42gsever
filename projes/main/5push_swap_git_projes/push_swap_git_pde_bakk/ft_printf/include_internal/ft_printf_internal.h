/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 15:19:04 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 12:14:17 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_map
{
	int				fd;
	int				pos;
	int				size;
	char			typ;
	int				min;
	int				spac;
	int				zero;
	int				width;
	int				pad;
	int				prec;
	int				pfill;
	int				bon;
	int				hash;
	int				apos;
	int				plus;
	long long		nb;
	long long		sci;
}				t_map;

char			*ft_ultoa(unsigned long long nb, long bas, t_map *map, char c);

void			ft_putchar_flags(char c, int fd, t_map *map, int check);
void			ft_putstr_flags(char *s, int fd, t_map *map, int check);
void			ft_nbrprinter_flags(char *s, int fd, t_map *map);
void			ft_putsign_fd(int fd, t_map *map);

void			ft_put0x(int fd, t_map *map);
void			ft_nbrflagger_flags(char *s, int fd, t_map *map);
void			ft_lastputstuff(char *s, int fd, t_map *map);
char			*ft_nbrputter_flags(char *s, int fd, t_map *map);

int				ft_amount(long long nb, long long base, t_map *map);
int				ft_absolutely(long long nb);
char			*ft_itoa_base(long long nb, long long base, t_map *map, char c);
int				ft_precpower(t_map *map, int base);
long long int	ft_floatrect(long double f, t_map *map);

void			ft_flagfinder(const char *s, t_map *map, va_list *args);
void			ft_secondflagfinder(const char *s, t_map *map, va_list *args);
void			ft_flagfiller(int fd, t_map *map, char *s);

int				ft_typefinder(const char *s, t_map *map, va_list *args);
int				ft_typefinder2(const char *s, t_map *map, va_list *args);
int				ft_typefinder3(const char *s, t_map *map, va_list *args);
int				ft_typefinder4(const char *s, t_map *map, va_list *args);

int				ft_thebigshort(const char *s, t_map *map, va_list *args);
int				ft_longfinder(const char *s, t_map *map, va_list *args);
int				ft_shortfinder(const char *s, t_map *map, va_list *args);
int				ft_longlongfinder(const char *s, t_map *map, va_list *args);
int				ft_shortshortfinder(const char *s, t_map *map, va_list *args);

char			*ft_floatjoin2(char *result, int i, char *ds, t_map *map);
char			*ft_floatjoin(char *s, char *ds, t_map *map);
void			ft_putscience(int fd, t_map *map);
void			ft_floatflagger(char *s, int fd, t_map *map);
void			ft_morebonusflags(const char *s, t_map *map);

long long		ft_round(double f, t_map *map, int base);
long long		ft_divpower(long long nb);
void			ft_floathandler(double f, long long base, t_map *map);
void			ft_science(double f, t_map *map);
int				ft_floatfinder(const char *s, t_map *map, va_list *args);

int				ft_floatingpointexception(double f, t_map *map);
int				ft_exponent(long long f);
int				ft_g2_finder(double f, t_map *map);
int				ft_g_finder(const char *s, t_map *map, double f);

t_map			*ft_initmap(void);
t_map			*ft_resetmap(t_map *map);
void			ft_writer(const char *s, t_map *map);

size_t			printf_strlen(const char *s);
void			*printf_memset(void *b, int c, size_t len);
void			*printf_calloc(size_t count, size_t size);
char			*printf_strchr(const char *s, int c);

#endif
