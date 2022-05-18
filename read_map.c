/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:42 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/18 17:33:40 by gfernand         ###   ########.fr       */
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
		count = ft_count(line, ' ');
		str = ft_split(line, ' ');
		i = 0;
		while (count > 0)
		{
			s = ft_split(str[i], ',');
			ft_splitfree(s);
			count--;
			i++;
		}
		ft_splitfree(str);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (s);
}

int	ft_rows(char *av)
{
	int		f;
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	f = 0;
	while (line != NULL)
	{
		f++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (f);
}

int	ft_columns(char *av)
{
	int		c;
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	c = ft_count(line, ' ');
	close(fd);
	free(line);
	return (c);
}

