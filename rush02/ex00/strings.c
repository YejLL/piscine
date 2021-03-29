/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:26:14 by hrazanam          #+#    #+#             */
/*   Updated: 2021/03/28 18:04:06 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hello.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	write(1, str, i);
}

int		count(char *str)
{
	int 	i;
	int 	j;

	i = -1;
	j = 0;
	while (str[++i])
		if (!(str[i] == ' ' && str[i - 1] == ' '))
			++j;
	return (j);
}

char	*trim(char *str)
{
	char 	*dest;
	int 	i;
	int		j;

	i = 0;
	j = 0;
	if (!(dest = malloc(count(str) + 1)))
		return (NULL);
	
	while (str[i])
	{
		if (!(str[i] == ' ' && str[i - 1] == ' ') && !(i == 0 && str[i] == ' ') && !(i == ft_strlen(str) - 1 && str[i] == ' '))
			dest[j++] = str[i];
		++i;
	}
	dest[j] = 0;
	return (dest);
}

void	ft_rev_char_tab(char *tab, int size)
{
	char	buff;
	int		i;

	i = 0;
	while (i < (size / 2))
	{
		buff = tab[i];
		tab[i] = tab[(size - 1 - i)];
		tab[(size - 1 - i)] = buff;
		++i;
	}
}

char	*format(char *str)
{
	char 	*dest;
	int 	nbSpaces;
	int 	i;
	int 	c;
	int 	k;

	nbSpaces = ft_strlen(str) / 3;
	c = 0;
	k = 0;
	i = ft_strlen(str) - 1;
	if (!(dest = malloc(i + nbSpaces + 1)))
		return (NULL);
	while (i >= 0)
	{
		if (c++ == 3)
		{
			c = 1;
			dest[k++] = ' ';
		}
		dest[k++] = str[i];
		--i;
	}
	dest[k] = 0;
	ft_rev_char_tab(dest, k);
	return (dest);
}

int		is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r');
}

int		ft_str_is_number(char *str)
{
	int 	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[i] != 0)
	{
		if ((str[i] < '0' || str[i] > '9') && !is_space(str[i]))
			return (0);
		++i;
	}
	return (1);
}

int		ft_str_is_only_number(char *str)
{
	int i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[i] != 0)
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
		++i;
	}
	return (1);
}

char	*str_no_spaces(char *str)
{
	char	*dest;
	int		nb_spaces;
	int		i;
	int		j;

	nb_spaces = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == '\t')
			nb_spaces++;
		i++;
	}
	if (!(dest = malloc(ft_strlen(str) - nb_spaces)))
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		if (!is_space(str[i]))
			dest[j++] = str[i];
		i++;
	}
	return (dest);
}

int		is_full_zero(char *str)
{
	while (*str)
	{
		if (*str++ != '0')
			return (0);
	}
	return (1);
}
