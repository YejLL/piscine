/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadeneux <gadeneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:31:47 by gadeneux          #+#    #+#             */
/*   Updated: 2021/03/28 17:20:40 by gadeneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hello.h"

int		main(int ac, char **av)
{
	char *contenu_du_fichier;
	char *dictionnaire;
	char *nombre;
	
	if (ac == 3)
	{
		dictionnaire = av[1];
		nombre = av[2];
	} 
	else 
	if (ac == 2)
	{
		dictionnaire = "numbers.dict";
		nombre = av[1];
	} 
	else
	{
		printf("Error");
		return (1);
	}
	contenu_du_fichier = lecture(dictionnaire);
	if (contenu_du_fichier == NULL)
	{
		printf("Missing dictionnary");
		return (2);
	}
	t_hello *liste;
	liste = creer_liste(ft_split(contenu_du_fichier, "\n"));
	if (!liste)
	{
		printf("Dict Error");
		return (3);
	}
	
	if (!ft_str_is_number(nombre))
	{
		printf("Error");
		return (4);
	}

	if (ft_strlen(str_no_spaces(nombre)) <= 0)
	{
		printf("Error");
		return (5);
	}

	if (is_full_zero(str_no_spaces(nombre)) && ft_strlen(str_no_spaces(nombre)) > 1)
	{
		printf("%s\n", récuperer_clé_selon_nombre(liste, 0));
		return (6);
	}
	
	char **arguments_du_nombre = ft_split(format(str_no_spaces(nombre)), " \n\t\v\f\r");
	
	int i;
	int taille;
	int nombre_de_zero;
	i = 0;
	while (arguments_du_nombre[i] != 0)
		++i;
	taille = i;
	i = 0;

	while (arguments_du_nombre[i] != 0)
	{
		nombre_de_zero = (taille - i - 1) * 3;

		if (recuperer_clé_selon_nombre_de_zero(liste, nombre_de_zero) == NULL)
		{
			printf("Error");
			return (5) ;
		}
		if (ft_atoi(arguments_du_nombre[i]) > 0 || taille == 1)
		{
			if (i > 0 && ft_atoi(arguments_du_nombre[i - 1]) > 0)
				printf(" ");
			convertir_centaine(liste, ft_atoi(arguments_du_nombre[i]));
		}	
		if (nombre_de_zero > 0 && ft_atoi(arguments_du_nombre[i]) != 0)
			printf(" %s", recuperer_clé_selon_nombre_de_zero(liste, nombre_de_zero));
		++i;
	}
	printf("\n");
	return (0);
}