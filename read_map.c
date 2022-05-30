/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:42 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/30 17:30:19 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_get_map(t_data data, char *av, int fd)
{
	char	*line;
	char	**str;
	char	**s;
	int		count;

	line = get_next_line(fd);
	while (line != NULL)
	{
		count = ft_count(line, ' ') - 1;
		str = ft_split(line, ' ');
		while (count >= 0)
		{
			s = ft_split(str[count], ',');
			ft_map_point(data, s, av, count);
			ft_splitfree(s);
			count--;
		}
		ft_splitfree(str);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (s);
}

int	**ft_map_point(t_data data, char **s, char *av, int count)
{
	static int	i;
	int			fd;
	int			row;

	row = ft_rows(av);
	fd = open(av, O_RDONLY);
	if (get_next_line(fd) != NULL)
	{
		free(get_next_line(fd));
		while (get_next_line(fd) != NULL)
			free(get_next_line(fd));
		data.height = malloc(sizeof(int *) * row);
		data.color = malloc(sizeof(int *) * row);
		i = -1;
		while(++i < row)
		{
			data.height[i] = malloc(sizeof(int *) * ft_columns(av));
			data.color[i] = malloc(sizeof(int *) * ft_columns(av));
		}
		i = 0;
		free(get_next_line(fd));
	}
	data.height[i][count] = ft_atoi_base(s[0], 10);
	data.color[i][count] = ft_atoi_base(s[1], 16);
	if (count == 0)
		i++;
	return (data.height);
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
