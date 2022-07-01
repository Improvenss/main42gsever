/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:49:37 by gsever            #+#    #+#             */
/*   Updated: 2022/07/01 19:51:01 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief	Fill the stack with arguments. etc: ./push_swap 9 8 -3 2 -7 5
 * @return	void
 * @param	ft_atoi Ascii to integer converting and returning int.
 * @bug		Not know bugs.
 */
void	stack_fill(int ac, char **av, t_base *base)
{
	int	n;
	int	i;

	n = 1;
	i = 0;
	printf("stack_fill func girdik\n");
	while (n <= base->start.size)
	{
		if (av[n][0] == '-')
		{
			av[n][0] = '+';
			base->a[i] = ft_atoi(av[n]);
			base->a[i] *= -1;
			printf(" - numara gorduk + koyup sayimizi negatif yaptik\n");
		}
		else if (av[n][0] == '0')
		{
			base->a[i] = 0;
			printf("sayimiz 0 olm\n");
		}
		else
			base->a[i] = ft_atoi(av[n]);
		printf("sayimizi integer'e cevirdik ft_atoi'yle\n");
		n++;
		if (n < ac)
		{
			printf("n'imiz ac'den kucuk i'yi arttiriyoruz\n");
			i++;
		}
	}
	printf("stack'imizi doldurduk artik stack_fill func cikabilirz\n");
}

/**
 * @brief	Fill the stack with argument's double quotations. --> ("")
 * etc: ./push_swap "9 8 -3 2 -7 5"
 * @return	void
 * @param	ft_atoi Ascii to integer converting and returning int.
 * @bug		Not know bugs.
 */
void	stack_fill_double_quotation(char **av, t_base *base)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (n < base->start.size)
	{
		if (av[n][0] == '-')
		{
			av[n][0] = '+';
			base->a[i] = ft_atoi(av[n]);
			base->a[i] *= -1;
		}
		else if (av[n][0] == '0')
			base->a[i] = 0;
		else
			base->a[i] = ft_atoi(av[n]);
		n++;
		if (n < base->start.size)
			i++;
	}
}

/** OKK
 * @brief	Check arguments, is the argument just an integer?
 * Checking if arguman count 2 or +.
 * @return	void
 * @param	check_num --> ./push_swap 9 8 -3 2 -7 5 -> Looking ("").
 * @param	check_num_double_quotation --> ./push_swap "9 8 -3 2 -7 5"
 * @bug		Not know bugs. It's working perfect.
 */
void	arg_checker(int argc, char **argv, t_base *base)
{
	printf("arg_checker kontrol ediyoruz\n");
	if (argc > 2)
	{
		base->start.size = argc - 1;
		printf("Argumanlarin sayilardan olusuyor\n");
		check_num(argc, argv);
		printf("check_num functionundan cikildi\n");
	}
	else if (argc == 2)
	{
		printf("Argumanin stringden olusuyor\n");
		check_num_double_quotation(argv[1], base);
	}
}
