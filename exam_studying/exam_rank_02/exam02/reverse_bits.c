#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int i;

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
}

unsigned char reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char result;

	i = 8;
	result = 0;
	while(i > 0)
	{
		result = result * 2 + (octet % 2);
		octet /= 2;
		i--;
	}
	return(result);
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int	main()
{
	unsigned char sample;
	unsigned char reversed;
	int	decimal;

	decimal = 3;
	sample = 'g';
	reversed = reverse_bits(sample);
	print_bits(sample);
	write(1, "\n", 1);
	swap_bits(sample);
	write(1, "\n", 1);
	print_bits(reversed);
	write(1, "\n", 1);
	print_bits(decimal);

	return(0);
}