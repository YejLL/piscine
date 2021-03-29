/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadeneux <gadeneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:01:12 by gadeneux          #+#    #+#             */
/*   Updated: 2021/03/28 18:08:53 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hello.h"

char	*lecture(char *file)
{
	char	*contenu;
	int		fd;
	int		i;

	i = 0;
	contenu = (char*)malloc(32000);
	if (contenu < 0)
		return (NULL);
	while (i < 32000)
	{
		contenu[i] = 0;
		i++;
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	read(fd, contenu, 32000);
	close(fd);
	return (contenu);
}
