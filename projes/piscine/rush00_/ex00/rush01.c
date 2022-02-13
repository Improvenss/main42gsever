/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoysal <tsoysal@42kocaeli.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:25:08 by tsoysal           #+#    #+#             */
/*   Updated: 2021/11/28 16:44:46 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_line(int x, int y)
{
	int	n;

	n = 0;
	while (n < x)
	{
		if (n == 0)
			ft_putchar('/');
		else if (n == x - 1)
			ft_putchar('\\');
		else
			ft_putchar('*');
		n++;
	}
	ft_putchar('\n');
	n = 0;
}

void	middle_lines(int x, int y)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	if (y >= 3)
	{
		while (j < y - 2)
		{	
			while (n < x)
			{
				if (n == 0 || n == x - 1)
					ft_putchar('*');
				else
					ft_putchar(' ');
				n++;
			}
			n = 0;
			j++;
			ft_putchar('\n');
		}
	}
	n = 0;
}

void	last_line(int x, int y)
{
	int	n;

	n = 0;
	if (y > 1)
	{
		while (n < x)
		{
			if (n == 0)
				ft_putchar('\\');
			else if (n == x - 1)
				ft_putchar('/');
			else
				ft_putchar('*');
			n++;
		}
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{	
	if (x > 0 && y > 0)
	{
		first_line(x, y);
		middle_lines(x, y);
		last_line(x, y);
	}
}
