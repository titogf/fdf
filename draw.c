/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:31 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/02 17:05:38 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_y(t_data *data);
static void	ft_p_x(t_data *data, int mx, int my);
static void	ft_p_y(t_data *data, int mx, int my);
static void	ft_isometric(t_data *data, int mx, int my, int n);

static void	ft_p_y(t_data *data, int mx, int my)
{
	data->brsh.x0 = mx * data->space + data->posx;
	data->brsh.y0 = my * data->space + data->posy;
	data->brsh.x1 = mx * data->space + data->posx;
	data->brsh.y1 = (my + 1) * data->space + data->posy;
}

static void	ft_p_x(t_data *data, int mx, int my)
{
	data->brsh.x0 = mx * data->space + data->posx;
	data->brsh.y0 = my * data->space + data->posy;
	data->brsh.x1 = (mx + 1) * data->space + data->posx;
	data->brsh.y1 = my * data->space + data->posy;
}

static void	ft_isometric(t_data *data, int mx, int my, int n)
{
	int	x;
	int	y;
	int	z;

	if (n == 0)
	{
		data->brsh.x0 = mx * data->space;
		data->brsh.y0 = my * data->space;
		z = data->height[my][mx] * data->space;
		x = (data->brsh.x0 - data->brsh.y0) * cos(0.524);
		y = -z + (data->brsh.y0 + data->brsh.x0) * sin(0.524);
		data->brsh.x0 = x + data->posx;
		data->brsh.y0 = y + data->posy;
	}
	else if (n == 1)
	{
		data->brsh.x1 = mx * data->space;
		data->brsh.y1 = my * data->space;
		z = data->height[my][mx] * data->space;
		x = (data->brsh.x1 - data->brsh.y1) * cos(0.524);
		y = -z + (data->brsh.y1 + data->brsh.x1) * sin(0.524);
		data->brsh.x1 = x + data->posx;
		data->brsh.y1 = y + data->posy;
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
			ft_p_y(data, mx, my);
			if (data->proyection == ISO)
			{
				ft_isometric(data, mx, my, 0);
				ft_isometric(data, mx, my + 1, 1);
			}
			data->brsh.c1 = data->color[my][mx];
			data->brsh.c2 = data->color[my + 1][mx];
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
			ft_p_x(data, mx, my);
			if (data->proyection == ISO)
			{
				ft_isometric(data, mx, my, 0);
				ft_isometric(data, mx + 1, my, 1);
			}
			data->brsh.c1 = data->color[my][mx];
			data->brsh.c2 = data->color[my][mx + 1];
			ft_bresenham(data);
		}
	}
	ft_draw_y(data);
}
