#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int	ascending(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*tmp;
	int		swap;

	tmp = lst;
	while (lst->next != 0)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

int	main()
{
	t_list	*lst;
	t_list	*lst1;
	t_list	*lst2;
	t_list	*sorted;
	
	lst = malloc(sizeof(t_list));
	lst1 = malloc(sizeof(t_list));
	lst2 = malloc(sizeof(t_list));
	sorted = malloc(sizeof(t_list));
	lst->data = 5;
	lst->next = lst1;
	lst1->data = 2;
	lst1->next = lst2;
	lst2->data = 8;
	lst2->next = NULL;
	sorted = lst;
	printf("before list: ");
	while (sorted)
	{
		printf("%d ", sorted->data);
		sorted = sorted->next;
	}
	printf("\n");
//	printf("hay aq ya: %d", sorted[0].data);
	sorted = sort_list(lst, ascending);
	printf("\nafter list: ");
	while (sorted)
	{
		printf("%d ", sorted->data);
		sorted = sorted->next;
	}
	free(lst);
	free(lst1);
	free(lst2);
	free(sorted);
}
