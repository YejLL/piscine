/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:10:25 by ccottin           #+#    #+#             */
/*   Updated: 2021/03/14 12:06:01 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar0();
void	ft_putchar1(int x);
void	ft_putchar2(int x);
void	ft_putchar3(int x);
void	ft_putchar4();

void	rush(int x, int y)
{
	int l;

	if (x < 1 || y < 1)
		ft_putchar0();
	l = 1;
	while (l <= y)
	{
		if (l == 1)
			ft_putchar1(x);
		else if (l < y)
			ft_putchar2(x);
		else
			ft_putchar3(x);
		ft_putchar4();
		l++;
	}
}
