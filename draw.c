/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:31 by gfernand          #+#    #+#             */
/*   Updated: 2022/09/19 19:01:37 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_len_map(t_data *data);
//static void	ft_bresenham(t_data *data, int x, int y);

static void	ft_len_map(t_data *data)
{
	if (data->columns < 30)
		data->location = 20;
	if (data->columns > 29 && data->columns < 60)
		data->location = 14;
	if (data->columns > 59 && data->columns < 80)
		data->location = 8;
	if (data->columns > 79 && data->columns < 120)
		data->location = 6;
	if (data->columns > 119 && data->columns < 160)
		data->location = 4;
	if (data->columns > 159 && data->columns < 260)
		data->location = 3;
	if (data->columns > 259)
		data->location = 1;
}

void	ft_draw(t_data *data)
{
	int	x;
	int	y;

	ft_len_map(data);
	data->posx = WIDE / 2 - data->columns * data->location / 2;
	data->posy = HEIGHT / 2 - data->rows * data->location / 2;
	y = 0;
	while (data->height[y] && y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			data->brsh.x0 = data->posx + x * data->location;// * cos(0.523599);
			data->brsh.y0 = data->posy + y * data->location - data->height[y][x] * data->location;// * sin(0.523599);
			ft_putpixel(data, x, y);
			/*data->brsh.x1 = data->posx + ((x + 1) * data->location) * cos(0.523599);
			data->brsh.y1 = data->brsh.y0;//- data->height[y][x + 1];
			ft_bresenham(data, x, y);*/
			x++;
		}
		y++;
	}
}

/*static void	ft_bresenham(t_data *data, int x, int y)
{
	int	dx;
	int	dy;
	int	p;

	dx = data->brsh.x1 - data->brsh.x0;
	dy = data->brsh.y1 - data->brsh.y0;
	p = 2 * dy - dx;
	while (data->brsh.x0 < data->brsh.x1)
	{
		if (p >= 0)
		{
			ft_putpixel(data, x, y);
			data->brsh.y0 = data->brsh.y0 + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			ft_putpixel(data, x, y);
			p = p + 2 * dy;
		}
		data->brsh.x0 = data->brsh.x0 + 1;
	}
}*/
