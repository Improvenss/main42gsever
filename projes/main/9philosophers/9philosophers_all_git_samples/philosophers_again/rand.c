#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	main(void)
{
	unsigned long long	i;

//	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", rand());
	}
//	i = rand();
//	printf("%llu\n", i);
}
