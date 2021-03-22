/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:54:46 by yejlee            #+#    #+#             */
/*   Updated: 2021/03/22 16:10:25 by yejlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int n;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		n = 0;
		while (to_find[n] == str[i + n])
		{
			if (to_find[n + 1] == '\0')
				return (str + i);
			n++;
		}
		i++;
	}
	return (0);
}
