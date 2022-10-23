/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:31 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/20 16:32:12 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_isometric(t_data *data, int mx, int my, int n);
static void	ft_draw_y(t_data *data);

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

void	ft_draw_x(t_data *data, int n)
{
	int	mx;
	int	my;

	if (n == 1)
	{
		data->div2 = 1;
		ft_len1(data);
	}
	else
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
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
