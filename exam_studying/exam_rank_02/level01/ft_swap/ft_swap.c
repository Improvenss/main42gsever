void	ft_swap(int	*a, int	*b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
#include <stdio.h>

int	main()
{
	int	a;
	int	b;

	a = 301;
	b = 931;
	ft_swap(&a, &b);
	printf("swapladiktan sonraki a degeri: %d\n", a);
}
*/
