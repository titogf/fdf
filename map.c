/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:42 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/31 12:47:52 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_len2(t_data *data, int space);
static int	ft_len3(t_data *data, int space, int x, int y);

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
	ft_read_color(data, fd);
}

void	ft_len1(t_data *data)
{
	int	size;
	int	space;

	size = data->columns * data->div2;
	if (size < 20)
		data->space = 20;
	if (size > 19 && size < 30)
		data->space = 14;
	if (size > 29 && size < 60)
		data->space = 8;
	if (size > 59 && size < 80)
		data->space = 6;
	if (size > 79 && size < 110)
		data->space = 4;
	if (size > 109 && size < 160)
		data->space = 2;
	if (size > 159)
		data->space = 1;
	space = data->space;
	data->posx = WIDE / 2 - data->columns / 2 * space / 2;
	data->posy = HEIGHT / 2 - data->rows / 2 * space;
	ft_len2(data, space);
}

static void	ft_len2(t_data *data, int space)
{
	int	x;
	int	y;

	if (data->space != 1)
	{
		y = -1;
		while (++y < data->rows)
		{
			x = -1;
			while (++x < data->columns)
			{
				if (ft_len3(data, space, x, y) == 1)
					return ;
			}
		}
	}
}

static int	ft_len3(t_data *data, int space, int x, int y)
{
	if (data->posx + x * space <= 0 || data->posx + x * space >= WIDE)
	{
		data->div2++;
		ft_len1(data);
		return (1);
	}
	if (data->posy + y * space - data->height[y][x] * space <= 0)
	{
		data->div2++;
		ft_len1(data);
		return (1);
	}
	if (data->posy + y * space - (data->height[y][x] * space) >= HEIGHT)
	{
		data->div2++;
		ft_len1(data);
		return (1);
	}
	return (0);
}
