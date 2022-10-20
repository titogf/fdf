/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:31 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/17 17:59:29 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_bresenham(t_data *data, int mx, int my);
static void	ft_isometric(t_data *data, int mx, int my, int n);
static void	ft_draw_y(t_data *data);

void	ft_putpixel(t_data *data, int mx, int my)
{
	double	x;
	double	y;

	x = data->brsh.x0;
	y = data->brsh.y0;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color[my][mx]);
}

static void	ft_bresenham(t_data *data, int mx, int my)
{
	double	p;
	double	dx;
	double	dy;
	int	stepy;
	int	stepx;

	//printf("X1--->%f\nX0--->%f\n", data->brsh.x1, data->brsh.x0);
	//printf("Y1--->%f\nY0--->%f\n", data->brsh.y1, data->brsh.y0);
	stepy = 1;
	stepx = 1;
	dx = data->brsh.x1 - data->brsh.x0;
	dy = data->brsh.y1 - data->brsh.y0;
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

static void	ft_isometric(t_data *data, int mx, int my, int n)
{
	double	x;
	double	y;
	int	z;

	if (n == 0)
	{
		data->brsh.x0 = mx * data->space;
		data->brsh.y0 = my * data->space;
		z = data->height[my][mx] * data->space;
		x = (data->brsh.x0 - data->brsh.y0) * cos(0.524) + data->posx;
		y = -z + (data->brsh.y0 + data->brsh.x0) / 2 + data->posy;
		data->brsh.x0 = x;
		data->brsh.y0 = y;
	}
	else
	{
		data->brsh.x1 = mx * data->space;
		data->brsh.y1 = my * data->space;
		z = data->height[my][mx] * data->space;
		x = (data->brsh.x1 - data->brsh.y1) * cos(0.524) + data->posx;
		y = -z + (data->brsh.y1 + data->brsh.x1) / 2 + data->posy;
		data->brsh.x1 = x;
		data->brsh.y1 = y;
	}
}

static void	ft_draw_y(t_data *data)
{
	int	mx;
	int	my;

	mx = 0;
	while (mx < data->columns)
	{
		my = 0;
		while (my < data->rows - 1)
		{
			ft_isometric(data, mx, my, 0);
			ft_isometric(data, mx, my + 1, 1);
			ft_putpixel(data, mx, my);
			ft_bresenham(data, mx, my);
			my++;
		}
		mx++;
	}
}

void	ft_draw_x(t_data *data)
{
	int	mx;
	int	my;

	data->div2 = 1;
	ft_len1(data);
	my = 0;
	while (my < data->rows)
	{
		mx = 0;
		while (mx < data->columns - 1)
		{
			ft_isometric(data, mx, my, 0);
			ft_isometric(data, mx + 1, my, 1);
			ft_bresenham(data, mx, my);
			ft_putpixel(data, mx, my);
			mx++;
		}
		my++;
	}
	ft_draw_y(data);
}
