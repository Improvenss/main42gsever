#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int		main(void)
{
	int a, b, *ptr1, *ptr2;

	a = 841;
	b = 74;
	ptr1 = &a;
	ptr2 = &b;
	ft_ultimate_div_mod(ptr1, ptr2);
	printf("Result (11)= %d\n", a);
	printf("Rest (27)= %d\n", b);
}
