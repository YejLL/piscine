/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 07:43:03 by ccottin           #+#    #+#             */
/*   Updated: 2021/03/14 10:25:20 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar0(void)
{
	write(1, "Un rectangle se doit d'exister", 31);
}

void	ft_putchar1(int x)
{
	int c;

	c = 1;
	while (c <= x)
	{
		if (c == 1 || c == x)
			write(1, "A", 1);
		else
			write(1, "B", 1);
		c++;
	}
}

void	ft_putchar2(int x)
{
	int c;

	c = 1;
	while (c <= x)
	{
		if (c == 1 || c == x)
			write(1, "B", 1);
		else
			write(1, " ", 1);
		c++;
	}
}

void	ft_putchar3(int x)
{
	int c;

	c = 1;
	while (c <= x)
	{
		if (c == 1 || c == x)
			write(1, "C", 1);
		else
			write(1, "B", 1);
		c++;
	}
}

void	ft_putchar4(void)
{
	write(1, "\n", 1);
}
