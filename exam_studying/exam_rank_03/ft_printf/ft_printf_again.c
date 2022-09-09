#include <unistd.h>
#include <stdarg.h>

int	g_val = 0;

void	ft_decimal(long des, int set, char *sign)
{
	if (des > set)
		ft_decimal((des / set), set, sign);
	write(1, &sign[des % set], 1);
	g_val++;
}

int	ft_printf(const char *format, ...)
{
	g_val = 0;
	va_list	ap;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				char	*str = va_arg(ap, char *);
				int		len = 0;
				while (str[len] != '\0')
					len++;
				g_val += len;
				write(1, str, len);
			}
			else if (*format == 'd')
			{
				int		des = va_arg(ap, int);
				if (des < 0)
				{
					write(1, "-", 1);
					g_val++;
					des *= -1;
				}
				ft_decimal(des, 10, "0123456789");
			}
			else if (*format == 'x')
			{
				int		hex = va_arg(ap, int);
				ft_decimal(hex, 16, "0123456789abcdef");
			}
			format++;
		}
		else
			write(1, format++, 1);
	}
	return (g_val);
}

#include <stdio.h>
int	main()
{
	ft_printf("ben %s %d yasindayim 61 yazacak -> %x\n", "gorkem SEVER", 21, 97);
	printf("ben %s %d yasindayim 61 yazacak -> %x\n", "gorkem SEVER", 21, 97);
}
