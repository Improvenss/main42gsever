#include <stdlib.h>

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	*ft_range(int start, int end)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * ft_abs(start - end) + 1);
	while (start < end)
	{
		arr[i] = start;
		start++;
		i++;
	}
	arr[i] = start;
	while (start > end)
	{
		arr[i] = start;
		start--;
		i++;
	}
	arr[i] = start;
	return (arr);
}

int	*ft_rrange(int start, int end)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * ft_abs(start - end) + 1);
	while (end > start)
	{
		arr[i] = end;
		end--;
		i++;
	}
	arr[i] = end;
	while (end < start)
	{
		arr[i] = end;
		end++;
		i++;
	}
	arr[i] = end;
	return (arr);
}

#include <stdio.h>
int	main()
{
	int	i;
	int	*annen;
	int *baban;

	i = 0;
	annen = ft_range(-1, 3);
	baban = ft_rrange(-1, 3);
	while (i <= 10)
	{
		printf("%d ", annen[i]);
		i++;
	}
	i = 0;
	printf("\n");
	while (i <= 10)
	{
		printf("%d ", baban[i]);
		i++;
	}
	return (0);
}
