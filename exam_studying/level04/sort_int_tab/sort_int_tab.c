#include <stdio.h>
#include <stdlib.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tmp;

	if (tab != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				i = -1;
			}
			i++;
		}
	}
}

int	main()
{
	int	arr[] = {145, 2, -35, 95, 90909, 0, -35, 2};
	int	i;

	sort_int_tab(arr, 7);
	i = 0;
	while (i <= 7)
	{
		printf("%d ", arr[i]);
		i++;
	}
	return (0);
}
