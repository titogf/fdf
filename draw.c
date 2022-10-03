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

static void	ft_bresenham(t_data *data, int x, int y);
static void	ft_draw2(t_data *data);

void	ft_putpixel(t_data *data, int x, int y)
{
	double	x0;
	double	y0;
	double	cs;
	double	sen;
	int	space;

	space = data->location;
	cs = cos(0.523599);
	sen = sin(0.523599);
	x0 = (data->brsh.x0 - data->brsh.y0 - data->height[y][x] * space) * cs;
	y0 = -data->height[y][x] + (data->brsh.y0 + data->brsh.x0) * sen;
	x0 = x0 + data->posx;
	y0 = y0 + data->posy;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, data->color[y][x]);
}

void	ft_draw(t_data *data)
{
	int	x;
	int	y;
	int	space;

	data->div2 = 1;
	ft_len1(data);
	space = data->location;
	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns - 1)
		{
			data->brsh.x0 = x * space;
			data->brsh.y0 = (y - data->height[y][x]) * space;
		//	ft_putpixel(data, x, y);
			data->brsh.x1 = (x + 1) * space;
			data->brsh.y1 = data->brsh.y0 - data->height[y][x + 1];
			if (x != data->columns - 1)
				ft_bresenham(data, x, y);
			x++;
		}
		y++;
	}
	ft_draw2(data);
}

static void	ft_draw2(t_data *data)
{
	int	x;
	int	y;
	int	space;

	space = data->location;
	x = 0;
	while (x < data->columns)
	{
		y = 0;
		while (y < data->rows - 1)
		{
			data->brsh.x0 = x * space;
			data->brsh.y0 = (y - data->height[y][x]) * space;
			data->brsh.x1 = data->brsh.x0;
			data->brsh.y1 = (y + 1 - data->height[y + 1][x]) * space;
			if (y != data->rows - 1)
				ft_bresenham(data, x, y);
			y++;
		}
		x++;
	}
}

static void	ft_bresenham(t_data *data, int x, int y)
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
	if (dy < 0)
	{
		dy = -dy;
		stepy = -1;
	}
	ft_putpixel(data, x, y);
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
			ft_putpixel(data, x, y);
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
				p = p + 2 * (dx -dy);
			}
			ft_putpixel(data, x, y);
		}
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
			data->brsh.y0 = data->brsh.y0 + 1;
			p = p + 2 * (dy - dx);
		}
		else
			p = p + 2 * dy;
		ft_putpixel(data, x, y);
		data->brsh.x0 = data->brsh.x0 + 1;
	}
}*/
