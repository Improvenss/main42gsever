/*
#include <stdio.h>

void	print_array(int	*arr)
{
	int	i;
	int	length;

	length = 1 + sizeof(*arr);
	i = 0;
	while (--length >= 0)
	{
		printf("%d ", arr[i++]);
	}
}
*/
int		max(int* tab, unsigned int len)
{
	unsigned int i;
	int tmp;

	i = 0;
	while (i < len - 1)
	{
		printf("\nonceki hali	[%d]:", i);
		print_array(tab);
		if (tab[i] < tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
			printf("\nsonraki hali	[%d]:", i);
			print_array(tab);
		}
		i++;
	}
	return (tab[0]);
}
/*
int	main()
{
	int	arr[] = {3, 2, 4, 1, 9};

	printf("\nmax bu mu simdi:%d\n", max(arr, 5));
}
*/
