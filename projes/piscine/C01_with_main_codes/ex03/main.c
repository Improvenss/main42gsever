#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int		main(void)
{
	int a, b, div, mod, *ptr1, *ptr2;

	a = 841;
	b = 74;
	ptr1 = &div;
	ptr2 = &mod;
	ft_div_mod(a, b, ptr1, ptr2);
	printf("Result (11)= %d\n", div);
	printf("Rest (27)= %d\n", mod); 
}
