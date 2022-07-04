#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (octet >= i)
		{
			write(1, "1", 1);
			octet %= i;
			i /= 2;
		}
		else
		{
			write(1, "0", 1);
			i /= 2;
		}
	}
	write(1, "\n", 1);
}

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char result;

	i = 8;
	result = 0;
	while (i > 0)
	{
		result = result * 2 + (octet % 2);
		octet /= 2;
		i--;
	}
	return (result);
}

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}

void	print_bits2(unsigned char octet)
{
	int	i;
	unsigned char result;

	i = 8;
	while (i > 0)
	{
		octet >> i;
		write(1, octet
	}
}

int	main()
{
	unsigned char g;
	unsigned char h;

	g = 'g';
	h = 'h';
	print_bits(g);
	g = reverse_bits(g);
	print_bits(g);
	g = swap_bits(g);
	print_bits(g);
	write(1, "\n", 1);
	print_bits2(h);
	write(1, "\n", 1);
	return (0);
}
