/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:10:25 by ccottin           #+#    #+#             */
/*   Updated: 2021/03/14 16:20:00 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush1(int x, int c);
void	rush2(int x, int c);
void	rush3(int x, int c);

void	rush(int x, int y)
{
	int l;
	int c;

	l = 1;
	if (x < 1 || y < 1)
		write(1, "Ceci est un message d'erreur", 29);
	while (l <= y)
	{
		c = 1;
		if (l == 1)
			rush1(x, c);
		else if (l < y)
			rush2(x, c);
		else
			rush3(x, c);
		ft_putchar(10);
		l++;
	}
}

void	rush1(int x, int c)
{
	while (c <= x)
	{
		if (c == 1 || c == x)
			ft_putchar('A');
		else
			ft_putchar('B');
		c++;
	}
}

void	rush2(int x, int c)
{
	while (c <= x)
	{
		if (c == 1 || c == x)
			ft_putchar('B');
		else
			ft_putchar(32);
		c++;
	}
}

void	rush3(int x, int c)
{
	while (c <= x)
	{
		if (c == 1 || c == x)
			ft_putchar('C');
		else
			ft_putchar('B');
		c++;
	}
}
