/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:29:05 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/07 12:25:59 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_brsh_negative(t_data *data);
static void		ft_brsh_y(t_data *data);
static void		ft_put_line(t_data *data, int n);
static double	ft_fraction(int start, int end, int current);

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

void	ft_bresenham(t_data *data)
{
	int		color;
	int		start;
	int		end;
	int		current;
	double	fraction;

	ft_brsh_negative(data);
	if (data->brsh.dx > data->brsh.dy)
	{
		start = data->brsh.x0;
		end = data->brsh.x1;
		data->brsh.p = 2 * data->brsh.dy - data->brsh.dx;
		while (data->brsh.x0 != data->brsh.x1)
		{
			ft_put_line(data, 1);
			current = data->brsh.x0;
			fraction = ft_fraction(start, end, current);
			color = interpolate(data->brsh.c1, data->brsh.c2, fraction);
			ft_putpixel(data, color);
		}
	}
	else
		ft_brsh_y(data);
}

static void	ft_brsh_y(t_data *data)
{
	int		color;
	int		start;
	int		end;
	int		current;
	double	fraction;

	start = data->brsh.y0;
	end = data->brsh.y1;
	data->brsh.p = 2 * data->brsh.dx - data->brsh.dy;
	while (data->brsh.y0 != data->brsh.y1)
	{
		ft_put_line(data, 2);
		current = data->brsh.y0;
		fraction = ft_fraction(start, end, current);
		color = interpolate(data->brsh.c1, data->brsh.c2, fraction);
		ft_putpixel(data, color);
	}
}

static double	ft_fraction(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}
