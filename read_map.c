/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:42 by gfernand          #+#    #+#             */
/*   Updated: 2022/09/29 14:12:04 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_color(t_data *data);

void	ft_malloc(t_data *data, int fd)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (line != NULL)
	{
		data->columns = ft_count(line, ' ');
		data->rows = 0;
		while (line != NULL)
		{
			printf("%s\n", line);
			data->rows++;
			free(line);
			line = get_next_line(fd);
		}
	}
	close(fd);
	data->height = malloc(sizeof(int *) * data->rows);
	data->color = malloc(sizeof(int *) * data->rows);
	i = -1;
	while (++i < data->rows)
	{
		data->height[i] = malloc(sizeof(int *) * data->columns);
		data->color[i] = malloc(sizeof(int *) * data->columns);
	}
}

void	ft_get_map(t_data *data, char *av, int fd)
{
	char	**str;
	char	**s;
	char	*line;
	int		y;
	int		x;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	y = -1;
	while (line != NULL && ++y >= 0)
	{
		x = ft_count(line, ' ');
		str = ft_split(line, ' ');
		while (x-- > 0)
		{
			s = ft_split(str[x], ',');
			data->height[y][x] = ft_atoi_base(s[0], 10);
			data->color[y][x] = ft_atoi_base(s[1], 16);
			ft_splitfree(s);
		}
		ft_splitfree(str);
		free(line);
		line = get_next_line(fd);
	}
	ft_put_color(data);
	close(fd);
}

static void	ft_put_color(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->color[y] && y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			if (data->color[y][x] == -1)
				data->color[y][x] = 16777215;
			x++;
		}
		y++;
	}
}
