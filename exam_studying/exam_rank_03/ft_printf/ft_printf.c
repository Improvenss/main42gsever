#include <unistd.h>
#include <stdarg.h>

int	g_val = 0;

void	ft_decimal(long dec, int set, char *sign)
{
	if (dec >= set)
		ft_decimal(dec / set, set, sign);
	write(1, &sign[dec % set], 1);
	g_val++;
}
/*
void	ft_hexadecimal(unsigned hex, unsigned set, char *sign)
{
	if (hex >= set)
		ft_hexadecimal(hex / set, set, sign);
	write(1, &sign[hex % set], 1);
	g_val++;
}
*/
int	ft_printf(const char *format, ...)
{
	g_val = 0;
	va_list(ap);
	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				int		len = 0;
				char	*str = va_arg(ap, char *);
				if (!str)
					str = "(null)";
				while (str[len] != '\0')
					len++;
				g_val += len;
				write(1, str, len);
			}
			else if (*format == 'd')
			{
				long long	dec = va_arg(ap, int);
				if (dec < 0)
				{
					write (1, "-", 1);
					g_val++;
					dec *= -1;
				}
					ft_decimal(dec, 10, "0123456789");
			}
			else if (*format == 'x')
			{
				long long	hex = va_arg(ap, int);
				ft_decimal(hex, 16, "0123456789abcdef");
				//ft_hexadecimal(hex, 16, "0123456789abcdef");
			}
			format++;
		}
		else
			g_val += write(1, format++, 1);
	}
	va_end(ap);
	return (g_val);
}
/*
#include <stdio.h>
#include <limits.h>
int	main()
{
	ft_printf("hello %s %d yasindayim %x\n", "ben gorkem", INT_MIN, INT_MAX);
	printf("hello %s %d yasindayim %x\n", "ben gorkem", INT_MIN, INT_MAX);
}
*/
