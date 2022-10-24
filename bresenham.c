/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:29:05 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/24 14:20:57 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_brsh_negative(t_data *data);
static void	ft_put_line(t_data *data, int n);

void	ft_bresenham(t_data *data, int mx, int my)
{
	ft_brsh_negative(data);
	if (data->brsh.dx > data->brsh.dy)
	{
		data->brsh.p = 2 * data->brsh.dy - data->brsh.dx;
		while (data->brsh.x0 != data->brsh.x1)
		{
			ft_put_line(data, 1);
			ft_putpixel(data, mx, my);
		}
	}
	else
	{
		data->brsh.p = 2 * data->brsh.dx - data->brsh.dy;
		while (data->brsh.y0 != data->brsh.y1)
		{
			ft_put_line(data, 2);
			ft_putpixel(data, mx, my);
		}
	}
}

static void	ft_put_line(t_data *data, int n)
{
	if (n == 1)
	{
		data->brsh.x0 = data->brsh.x0 + data->brsh.stepx;
		if (data->brsh.p < 0)
			data->brsh.p = data->brsh.p + 2 * data->brsh.dy;
		else
		{
			data->brsh.y0 = data->brsh.y0 + data->brsh.stepy;
			data->brsh.p = data->brsh.p + 2 * (data->brsh.dy - data->brsh.dx);
		}
	}
	if (n == 2)
	{
		data->brsh.y0 = data->brsh.y0 + data->brsh.stepy;
		if (data->brsh.p < 0)
			data->brsh.p = data->brsh.p + 2 * data->brsh.dx;
		else
		{
			data->brsh.x0 = data->brsh.x0 + data->brsh.stepx;
			data->brsh.p = data->brsh.p + 2 * (data->brsh.dx - data->brsh.dy);
		}
	}
}

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
