/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:42 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/18 13:53:08 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

char	**ft_get_map(int fd)
{
	char	*line;
	char	**str;
	char	**s;
	int		i;
	int		count;

	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("FIRST->->%s\n", line);
		count = ft_count(line, ' ');
		str = ft_split(line, ' ');
		i = 0;
		while (count > 0)
		{
			s = ft_split(str[i], ',');
			count--;
			i++;
		}
		ft_splitfree(str, count);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (s);
}

int	ft_rows(int fd)
{
	int		f;
	char	*line;

	line = get_next_line(fd);
	printf("SECOND->%s\n", line);
	f = 1;
	while (line != NULL)
	{
		f++;
		free(line);
		line = get_next_line(fd);
		printf("SECOND->%s\n", line);
	}
	free(line);
	close(fd);
	printf("ESTO ES LA F: %i", f);
	return (f);
}

int	ft_columns(char *av)
{
	int		c;
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	printf("SECOND->%s\n", line);
	c = ft_count(line, ' ');
	close(fd);
	free(line);
	return (c);
}

