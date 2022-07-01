/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:09:00 by gsever            #+#    #+#             */
/*   Updated: 2022/07/01 20:01:13 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief	Check if a stack's numbers is sorted.
 * @return	void
 * @param	ft_free Free all stacks.
 * @bug		Not know bugs.
 */
void	is_sorted(t_base *base)
{
	int		i;

	i = 0;
	while (i + 1 < base->start.size)
	{
		if (base->a[i] < base->a[i + 1])
			i++;
		else
			return ;
	}
	ft_free(base);
}

/**
 * @brief	Check if a stack's numbers is repeated.
 * @return	void
 * @param	ft_error If have problem, writing "Error" and exit program.
 * @bug		Not know bugs.
 */
void	is_repeated(t_base *base)
{
	int	i;
	int	j;

	i = 0;
	printf("is_repeated girdik simdi dongumuz basliyor\n");
	while (i < base->start.size)
	{
		j = i + 1;
		printf("i'miz start.size'sinin hepsine varana kadar ilerlemaye basladi\n");
		while (j < base->start.size)
		{
			printf("sayilarimizin baslangicindan itibaren secip onu hepsinle kontrol ediyoruz.	ai%d	aj%d\n", base->a[i], base->a[j]);
			if (base->a[i] == base->a[j])
				ft_error("Error\n");
			printf("ayni sayimiz yok\n");
			j++;
		}
		i++;
	}
	printf("dongumuz bitti cikiyoruz\n");
}

/**
 * @brief	It's just writing string and start exit(1);
 * @return	1
 * @bug		Not know bugs.
 */
int	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit (1);
	return (1);
}

/**
 * @brief	Just check if there are only numbers.
 * @return	void
 * @param	is_digit Scanning string, all argumans are digit.
 * @param	ft_error If have problem, writing "Error" and exit program.
 * @bug		Not know bugs.
 */
void	check_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	printf("check_num func girildi\n");
	while (i < ac)
	{
		printf("dongumuz basladi\n");
		j = 0;
		while (av[i][j])
		{
			printf("sayimiz	:%d\n", av[i][j]);
			if (ft_isdigit(av[i][j]))
				ft_error("Error\n");
			printf("sayimiz ft_isdigit functionundan gecti, sayimiz doru\n");
			if (av[i][j] == '-')
			{
				if (!(av[i][j + 1] >= '1' && av[i][j + 1] <= '9'))
					ft_error("Error\n");
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief	We are checking if the double quotation's output is correct or not.
 * @return	void
 * @param	arguman_length Counts numbers seperated by spaces in a string.
 * @param	is_digit Scanning string, all argumans are digit.
 * @param	ft_error If have problem, writing "Error" and exit program.
 * @bug		Not know bugs.
 */
void	check_num_double_quotation(char *av, t_base *base)
{
	int	i;

	i = 0;
	base->start.size = (int)arguman_length(av, ' ');
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			ft_error("Error\n");
		if (av[i] == '-')
		{
			if (!(av[i + 1] >= '0' && av[i + 1] <= '9'))
				ft_error("Error\n");
		}
		i++;
	}
}
