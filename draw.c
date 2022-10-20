/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:31 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/20 15:56:23 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_brsh_negative(t_data *data);
static void	ft_bresenham(t_data *data, int mx, int my);
static void	ft_isometric(t_data *data, int mx, int my, int n);
static void	ft_draw_y(t_data *data);


static void	ft_brsh_negative(t_data *data)
{
	data->brsh.dx = data->brsh.x1 - data->brsh.x0;
	data->brsh.dy = data->brsh.y1 - data->brsh.y0;
	data->brsh.stepy = 1;
	data->brsh.stepx = 1;
	if (data->brsh.dy < 0)
	{
		data->brsh.dy = -data->brsh.dy;
		data->brsh.stepy = -1;
	}
	if (data->brsh.dx < 0)
	{
		data->brsh.dx = -data->brsh.dx;
		data->brsh.stepx = -1;
	}
}

static void	ft_bresenham(t_data *data, int mx, int my)
{
	double	p;

	ft_brsh_negative(data);
	if (data->brsh.dx > data->brsh.dy)
	{
		p = 2 * data->brsh.dy - data->brsh.dx;
		while (data->brsh.x0 != data->brsh.x1)
		{
			data->brsh.x0 = data->brsh.x0 + data->brsh.stepx;
			if (p < 0)
				p = p + 2 * data->brsh.dy;
			else
			{
				data->brsh.y0 = data->brsh.y0 + data->brsh.stepy;
				p = p + 2 * (data->brsh.dy - data->brsh.dx);
			}
			ft_putpixel(data, mx, my);
		}
	}
	else
	{
		p = 2 * data->brsh.dx - data->brsh.dy;
		while (data->brsh.y0 != data->brsh.y1)
		{
			data->brsh.y0 = data->brsh.y0 + data->brsh.stepy;
			if (p < 0)
				p = p + 2 * data->brsh.dx;
			else
			{
				data->brsh.x0 = data->brsh.x0 + data->brsh.stepx;
				p = p + 2 * (data->brsh.dx - data->brsh.dy);
			}
			ft_putpixel(data, mx, my);
		}
	}
}

static void	ft_isometric(t_data *data, int mx, int my, int n)
{
	double	x;
	double	y;
	int		z;

	if (n == 0)
	{
		data->brsh.x0 = mx * data->space;
		data->brsh.y0 = my * data->space;
		z = data->height[my][mx] * data->space;
		x = (data->brsh.x0 - data->brsh.y0) + data->posx;
		y = -z + (data->brsh.y0 + data->brsh.x0) / 2 + data->posy;
		data->brsh.x0 = x;
		data->brsh.y0 = y;
	}
	else
	{
		data->brsh.x1 = mx * data->space;
		data->brsh.y1 = my * data->space;
		z = data->height[my][mx] * data->space;
		x = (data->brsh.x1 - data->brsh.y1) + data->posx;
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
