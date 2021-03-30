/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:56:06 by yejlee            #+#    #+#             */
/*   Updated: 2021/03/30 13:39:59 by yejlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int						ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char					*ft_strdup(char *src)
{
	int src_len;
	char*strr;
	int i;

	src_len = ft_strlen(src);
	strr = (char *)malloc(src_len + 1);
	if (strr == NULL)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		strr[i] = src[i];
		i++;
	}
	strr[i] = '\0';
	return (strr);
}

struct	s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*struct_tab;
	int				i;

	struct_tab = (t_stock_str*)malloc((ac + 1) * sizeof(t_stock_str));
	if (struct_tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		struct_tab[i].size = ft_strlen(av[i]);
		struct_tab[i].str = av[i];
		struct_tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	struct_tab[i].str = 0;
	return (struct_tab);
}
