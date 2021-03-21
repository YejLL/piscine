/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:52:27 by yejlee            #+#    #+#             */
/*   Updated: 2021/03/20 17:35:15 by yejlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*is_lowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	is_lowcase(str);
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] = str[0] - 32;
	}
	while (str[i])
	{
		if ((str[i] < '0') || (str[i] > 57 && str[i] < 65)
			|| (str[i] > 90 && str[i] < 97)
			|| (str[i] >= 123 && str[i] < 127))
		{
			if (str[i + 1] > 96 && str[i + 1] < 123)
			{
				str[i + 1] = str[i + 1] - 32;
			}
		}
		i++;
	}
	return (str);
}
