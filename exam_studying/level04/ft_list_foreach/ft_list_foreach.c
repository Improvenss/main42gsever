#include <stdio.h>
#include "ft_list.h"

void	annen(void *n)
{
	int	*i;

	i = (int *)n;
	*i *= 2;
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*tmp;

	tmp = begin_list;
	while (tmp)
	{
		(*f)(tmp->data);
		tmp = tmp->next;
	}
}

#include <stdlib.h>
int	main()
{
	t_list	*tmp;
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;

	lst1 = malloc(sizeof(t_list));
	lst2 = malloc(sizeof(t_list));
	lst3 = malloc(sizeof(t_list));
	lst1->data = (int *)2;
	lst1->next = lst2;
	lst2->data = (int *)9;
	lst2->next = lst3;
	lst3->data = (int *)12;
	lst3->next = NULL;
	tmp = lst1;
	printf("Before :");
	while (tmp != 0)
	{
		printf("%d ", *(int *)tmp->data);
		tmp = tmp->next;
	}
	ft_list_foreach(tmp, annen);
	tmp = lst1;
	printf("\nAfter :");
	while (tmp != 0)
	{
		printf("%d ", *(int *)tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	free(tmp);
	free(lst1);
	free(lst2);
	free(lst3);
	return (0);
}
