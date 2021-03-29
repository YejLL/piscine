/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadeneux <gadeneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:08:32 by gadeneux          #+#    #+#             */
/*   Updated: 2021/03/28 15:30:46 by gadeneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hello.h"

int		is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != 0)
		if (charset[i++] == c)
			return (1);
	return (0);
}

int		word_count(char *str, char *charset)
{
	int i;
	int j;
	int r;

	i = -1;
	j = 0;
	r = 0;
	while (str[++i] != 0)
		if (!is_charset(str[i], charset) && (is_charset(str[i + 1], charset)
		|| str[i + 1] == 0))
			++r;
	return (r);
}

#include <stdio.h>
char	*cut(char *str, int from, char *charset)
{
	char	*dest;
	int		i;
	int		l;

	l = 0;
	i = from;
	while (str[i] != 0 && i >= 0 && !is_charset(str[i--], charset))
		++l;
	i = 0;
	if (!(dest = (char*)malloc(l + 1)))
		return (0);
	while (str[from] != 0 && from >= 0 && !is_charset(str[from], charset))
		dest[i++] = str[from--];
	ft_rev_char_tab(dest, l);
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		words;
	int		i;
	int		j;

	if ((words = word_count(str, charset)) <= 0)
	{
		if (!(strs = (char**)malloc(sizeof(char*) * 1)))
			return (0);
		strs[0] = 0;
		return (strs);
	}
	if (!(strs = (char**)malloc(sizeof(char*) * (words + 1))))
		return (0);
	i = -1;
	j = 0;
	while (str[++i] != 0)
		if (!is_charset(str[i], charset) && (is_charset(str[i + 1], charset)
		|| str[i + 1] == 0))
			strs[j++] = cut(str, i, charset);
	strs[j] = 0;
	return (strs);
}
