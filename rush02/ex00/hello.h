/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadeneux <gadeneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:17 by gadeneux          #+#    #+#             */
/*   Updated: 2021/03/28 17:40:02 by gadeneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELLO_H
# define HELLO_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct			s_hello
{
	struct s_hello	*suivant;
	char			*key;
	char			*value;
}						t_hello;

char					**ft_split (char *str, char *charset);
int						ft_atoi(char *str);
int						ft_strlen(char *str);

int						recuperer_index(char *str);
t_hello					*creer_element(char *str);
t_hello					*creer_liste(char **str);
void					afficher_liste(t_hello *liste);
char					*recuperer_clé_selon_nombre_de_zero(t_hello *liste,
						unsigned long zeros);

char					*ft_strdup(char *src);

char					*unitées(t_hello *liste, int nb);
char					*dizaines_non_combinables(t_hello *liste, int nb);
char					*dizaines_combinables(t_hello *liste, int nb);
void					convertir_centaine(t_hello *liste, unsigned int nb);
unsigned long			compter_les_caracteres(char *str);
char					*récuperer_clé_selon_nombre(t_hello *liste, int nb);

void					ft_rev_char_tab(char *tab, int size);
char					*trim(char *str);
char					*format(char *str);
int						is_space(char c);
int						ft_str_is_number(char *str);
int						ft_str_is_only_number(char *str);
char					*str_no_spaces(char *str);
int						is_full_zero(char *str);

char					*lecture(char *file);

#endif
