/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:32:07 by yejlee            #+#    #+#             */
/*   Updated: 2021/03/16 12:34:01 by yejlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int change;

	change = *a;
	*a = *b;
	*b = change;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		ft_swap(&tab[i], &tab[j]);
		i++;
		j--;
	}
}
