/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:55:04 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/31 17:06:32 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_data *data, double alpha, int mx, int my, int n);
static void	rotate_y(t_data *data, double beta, int mx, int my);
static void	rotate_z(t_data *data, double gamma, int n);

void	ft_rotate(t_data *data, int mx, int my, int n)
{
	rotate_x(data, data->brsh.alpha, mx, my, n);
	rotate_y(data, data->brsh.beta, mx, my);
	rotate_z(data, data->brsh.gamma, n);
}

static void	rotate_x(t_data *data, double alpha, int mx, int my, int n)
{
	int	y;
	int	z;

	if (n == 0)
	{
		y = data->brsh.y0 * cos(alpha) + data->height[my][mx] * sin(alpha);
		z = -data->brsh.y0 * sin(alpha) + data->height[my][mx] * cos(alpha);
		data->brsh.y0 = y;
	}
	if (n == 1)
	{
		y = data->brsh.y1 * cos(alpha) + data->height[my][mx] * sin(alpha);
		z = -data->brsh.y1 * sin(alpha) + data->height[my][mx] * cos(alpha);
		data->brsh.y1 = y;
	}
}

static void	rotate_y(t_data *data, double beta, int mx, int my)
{
	int	x;
	int	z;

	x = data->brsh.x0 * cos(beta) + data->height[my][mx] * sin(beta);
	z = -data->brsh.x0 * sin(beta) + data->height[my][mx] * cos(beta);
	data->brsh.x0 = x;
}

static void	rotate_z(t_data *data, double gamma, int n)
{
	int	x;
	int	y;

	if (n == 0)
	{
		x = data->brsh.x0 * cos(gamma) - data->brsh.y0 * sin(gamma);
		y = data->brsh.x0 * sin(gamma) + data->brsh.y0 * cos(gamma);
		data->brsh.x0 = x;
		data->brsh.y0 = y;
	}
	if (n == 1)
	{
		x = data->brsh.x1 * cos(gamma) - data->brsh.y1 * sin(gamma);
		y = data->brsh.x1 * sin(gamma) + data->brsh.y1 * cos(gamma);
		data->brsh.x1 = x;
		data->brsh.y1 = y;
	}
}
