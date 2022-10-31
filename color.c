/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:48:15 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/31 13:14:54 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_color(t_data *data, int x, int y, int c);

void	ft_read_color(t_data *data, int fd)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	while (data->color[y] && y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			c = data->height[y][x];
			if (c < 0)
				c *= -1;
			if (data->color[y][x] == -1)
				ft_put_color(data, x, y, c);
			x++;
		}
		y++;
	}
	close(fd);
}

static void	ft_put_color(t_data *data, int x, int y, int c)
{
	if (c == 0)
		data->color[y][x] = 16777215;
	else if (c < 31)
		data->color[y][x] = 65280;
	else if (c < 51)
		data->color[y][x] = 8454658;
	else if (c > 50)
		data->color[y][x] = 12988888;
}

int	interpolate(int color1, int color2, float fraction)
{
	unsigned char	r[2];
	unsigned char	g[2];
	unsigned char	b[2];

	if (color1 == color2)
		return (color1);
	r[0] = (color1 >> 16) & 0xff;
	r[1] = (color2 >> 16) & 0xff;
	g[0] = (color1 >> 8) & 0xff;
	g[1] = (color2 >> 8) & 0xff;
	b[0] = color1 & 0xff;
	b[1] = color2 & 0xff;
	return (int) ((r[1] - r[0]) * fraction + r[0]) << 16 |
		(int) ((g[1] - g[0]) * fraction + g[0]) << 8 |
		(int) ((b[1] - b[0]) * fraction + b[0]);
}
