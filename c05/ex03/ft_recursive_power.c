/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:18:15 by yejlee            #+#    #+#             */
/*   Updated: 2021/03/24 12:41:30 by yejlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if ((power % 2) == 0)
		return (ft_recursive_power(nb * nb, power / 2));
	else
		return (nb * ft_recursive_power(nb * nb, (power - 1) / 2));
}
