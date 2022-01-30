#include <stdio.h>

void	ft_ultimate_ft(int *********);

int		main(void)
{
	int a;
	int *ptr1, **ptr2, ***ptr3, ****ptr4, *****ptr5, ******ptr6, *******ptr7, ********ptr8, *********ptr9;

	a = 21;
	ptr1 = &a;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;
	printf("Avant (21): %d\n", a);
	ft_ultimate_ft(ptr9);
	printf("Apres (42): %d\n", a);
}
