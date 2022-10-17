/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:31 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/03 17:40:52 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_bresenham(t_data *data, int mx, int my);
static void	ft_vertical(t_data *data);

void	ft_putpixel(t_data *data, int mx, int my)
{
	double	x;
	double	y;

	x = (data->brsh.x0 - data->brsh.y0) * cos(0.5249 + data->posx;
	x = (data->brsh.x0 - data->brsh.y0) - data->location * data->height[my][mx] + data->posx;
	y = (data->brsh.y0 + data->brsh.x0) * sin(0.524) + data->posy;
	//x = data->brsh.x0 + data->posx;
	//y = data->brsh.y0 + data->posy;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color[my][mx]);
}

void	ft_horizontal(t_data *data)
{
	int	mx;
	int	my;
	int	space;

	data->div2 = 1;
	ft_len1(data);
	space = data->location;
	my = 0;
	while (my < data->rows)
	{
		mx = 0;
		while (mx < data->columns - 1)
		{
			data->brsh.x0 = mx * space;
			data->brsh.y0 = (my - data->height[my][mx]) * space;
			data->brsh.x1 = (mx + 1) * space;
			data->brsh.y1 = (my - data->height[my][mx + 1]) * space;
			ft_bresenham(data, mx, my);
			mx++;
		}
		my++;
	}
	ft_vertical(data);
}

static void	ft_vertical(t_data *data)
{
	int	mx;
	int	my;
	int	space;

	space = data->location;
	mx = 0;
	while (mx < data->columns)
	{
		my = 0;
		while (my < data->rows - 1)
		{
			data->brsh.x0 = mx * space;
			data->brsh.y0 = (my - data->height[my][mx]) * space;
			data->brsh.x1 = data->brsh.x0;
			data->brsh.y1 = (my + 1 - data->height[my + 1][mx]) * space;
			ft_bresenham(data, mx, my);
			my++;
		}
		mx++;
	}
}

static void	ft_bresenham(t_data *data, int mx, int my)
{
	int	p;
	int	dx;
	int	dy;
	int	stepy;
	int	stepx;

	dx = data->brsh.x1 - data->brsh.x0;
	dy = data->brsh.y1 - data->brsh.y0;
	stepy = 1;
	stepx = 1;
	ft_putpixel(data, mx, my);
	if (dy < 0)
	{
		dy = -dy;
		stepy = -1;
	}
	if (dx < 0)
	{
		dx = -dx;
		stepx = -1;
	}
	if (dx > dy)
	{
		p = 2 * dy - dx;
		while (data->brsh.x0 != data->brsh.x1)
		{
			data->brsh.x0 = data->brsh.x0 + stepx;
			if (p < 0)
				p = p + 2 * dy;
			else
			{
				data->brsh.y0 = data->brsh.y0 + stepy;
				p = p + 2 * (dy - dx);
			}
			ft_putpixel(data, mx, my);
		}
	}
	else
	{
		p = 2 * dx - dy;
		while (data->brsh.y0 != data->brsh.y1)
		{
			data->brsh.y0 = data->brsh.y0 + stepy;
			if (p < 0)
				p = p + 2 * dx;
			else
			{
				data->brsh.x0 = data->brsh.x0 + stepx;
				p = p + 2 * (dx - dy);
			}
			ft_putpixel(data, mx, my);
		}
	}
}
