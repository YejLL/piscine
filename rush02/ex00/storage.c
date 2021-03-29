/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadeneux <gadeneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:20:43 by hrazanam          #+#    #+#             */
/*   Updated: 2021/03/28 17:21:29 by gadeneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hello.h"

int        recuperer_index(char *str)
{
    int result;

    result = 0;
    while (*str)
        if (*str++ == '0')
            result ++;
    return (result / 3);
}

t_hello *creer_element(char *str)
{
	char **str_split;
	
    str_split = ft_split(str, ":");
	
	int i;
	i = 0;
	while (str_split[i])
		i++;
	if (i != 2)
		return 0;
	
	t_hello *h = malloc(sizeof(t_hello));
	if (!h)
		return (NULL);

	if (!ft_str_is_only_number(str_split[0]))
		return (NULL);
	printf("%s <--\n", str_split[0]);
		
	h->key = str_split[0];
	h->value = trim(str_split[1]);
	h->suivant = 0;
	return (h);
}

t_hello *creer_liste(char **str)
{
	int i;
	t_hello *h;
	t_hello *debut;

	i = 0;
	if (str == 0)
		return (NULL);
		
	if (!(debut = creer_element(str[i])))
		return (NULL);

	h = debut;
	i = 1;
	while (str[i])
	{
		t_hello *suivant;

		if (!(suivant = creer_element(str[i])))
			return (NULL);
			
		h->suivant = suivant;
		h = suivant;
		++i;
	}
	h->suivant = 0;
	return (debut);
}

void	afficher_liste(t_hello *liste)
{
	while (liste != NULL)
	{
		printf("indice '%s' et valeur %s  \n", liste->key, liste->value);
		liste = liste->suivant;
	}
}

char	*recuperer_clé_selon_nombre_de_zero(t_hello *liste, unsigned long zeros)
{
	while (liste != NULL)
	{
		if (compter_les_caracteres(liste->key) - 1 == zeros)
			return (liste->value);
		liste = liste->suivant;
	}
	return (NULL);
}

char	*récuperer_clé_selon_nombre(t_hello *liste, int nb)
{
	int i;

	i = 0;
	while (liste != NULL)
	{
		if (ft_atoi(liste->key) == nb)
			return (liste->value);
		liste = liste->suivant;
	}
	return (NULL);
}

unsigned long	compter_les_caracteres(char *str)
{
	unsigned long nb;

	nb = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			nb ++;
		str++;
	}
	return (nb);
}