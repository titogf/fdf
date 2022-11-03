/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:31 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/02 18:41:12 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_y(t_data *data);
static void	ft_p_v(t_data *data, int mx, int my, int n);
static void	ft_colocation(t_data *data, int mx, int my, int n);
static void	ft_isometric(t_data *data);

static void	ft_isometric(t_data *data)
{
	int	x;
	int	y;

	x = (data->brsh.x0 - data->brsh.y0) * cos(0.524);
	y = -data->brsh.z0 + (data->brsh.y0 + data->brsh.x0) * sin(0.524);
	data->brsh.x0 = x + data->columns * data->space / 2;
	data->brsh.y0 = y;
	x = (data->brsh.x1 - data->brsh.y1) * cos(0.524);
	y = -data->brsh.z1 + (data->brsh.y1 + data->brsh.x1) * sin(0.524);
	data->brsh.x1 = x + data->columns * data->space / 2;
	data->brsh.y1 = y;
}

static void	ft_p_v(t_data *data, int mx, int my, int n)
{
	if (n == 1)
	{
		data->brsh.x0 = mx * data->space;
		data->brsh.y0 = my * data->space;
		data->brsh.x1 = (mx + 1) * data->space;
		data->brsh.y1 = my * data->space;
		data->brsh.z0 = data->height[my][mx] * data->space;
		data->brsh.z1 = data->height[my][mx + 1] * data->space;
	}
	else
	{
		data->brsh.x0 = mx * data->space;
		data->brsh.y0 = my * data->space;
		data->brsh.x1 = mx * data->space;
		data->brsh.y1 = (my + 1) * data->space;
		data->brsh.z0 = data->height[my][mx] * data->space;
		data->brsh.z1 = data->height[my + 1][mx] * data->space;
	}
}

static void	ft_colocation(t_data *data, int mx, int my, int n)
{
	data->brsh.x0 += data->posx;
	data->brsh.x1 += data->posx;
	data->brsh.y0 += data->posy;
	data->brsh.y1 += data->posy;
	if (n == 1)
	{
		data->brsh.c1 = data->color[my][mx];
		data->brsh.c2 = data->color[my][mx + 1];
	}
	else
	{
		data->brsh.c1 = data->color[my][mx];
		data->brsh.c2 = data->color[my + 1][mx];
	}
}

static void	ft_draw_y(t_data *data)
{
	int	mx;
	int	my;

	mx = -1;
	while (++mx < data->columns)
	{
		my = -1;
		while (++my < data->rows - 1)
		{
			ft_p_v(data, mx, my, 2);
			ft_rotate(data);
			if (data->proyection == ISO)
				ft_isometric(data);
			ft_colocation(data, mx, my, 2);
			ft_bresenham(data);
		}
	}
}

void	ft_draw_x(t_data *data, int n)
{
	int	mx;
	int	my;

	ft_legend(data, n);
	my = -1;
	while (++my < data->rows)
	{
		mx = -1;
		while (++mx < data->columns - 1)
		{
			ft_p_v(data, mx, my, 1);
			ft_rotate(data);
			if (data->proyection == ISO)
				ft_isometric(data);
			ft_colocation(data, mx, my, 1);
			ft_bresenham(data);
		}
	}
	ft_draw_y(data);
}
