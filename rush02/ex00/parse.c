/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadeneux <gadeneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 08:28:08 by gadeneux          #+#    #+#             */
/*   Updated: 2021/03/28 18:27:28 by gadeneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hello.h"

char	*unitées(t_hello *liste, int nb)
{
	return (récuperer_clé_selon_nombre(liste, nb));
}

char	*dizaines_non_combinables(t_hello *liste, int nb)
{
	return (récuperer_clé_selon_nombre(liste, nb));
}

char	*dizaines_combinables(t_hello *liste, int nb)
{
	return (récuperer_clé_selon_nombre(liste, nb));
}

void	convertir_centaine(t_hello *liste, unsigned int nb)
{
	if (nb < 10)
		ft_putstr(unitées(liste, nb));
	else if (nb >= 10 && nb <= 19)
		ft_putstr(dizaines_non_combinables(liste, nb));
	else if (nb >= 20 && nb <= 99)
	{
		ft_putstr(dizaines_combinables(liste, nb - (nb % 10)));
		if (nb % 10 > 0)
		{
			ft_putstr(" ");
			ft_putstr(unitées(liste, nb % 10));
		}	
	} 
	else if (nb > 99 && nb <= 999)
	{
		ft_putstr(unitées(liste, nb / 100));
		ft_putstr(" ");
		ft_putstr(récuperer_clé_selon_nombre(liste, 100));
		if (nb % 100 > 0)
		{
			ft_putstr(" ");
			convertir_centaine(liste, nb % 100);
		}
	}
}
