/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:55:04 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/07 12:26:36 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_data *data, double alpha,int n);
static void	rotate_y(t_data *data, double beta, int n);
static void	rotate_z(t_data *data, double gamma, int n);

void	ft_rotate(t_data *data)
{
	rotate_x(data, data->brsh.alpha, 0);
	rotate_y(data, data->brsh.beta, 0);
	rotate_z(data, data->brsh.gamma, 0);
	rotate_x(data, data->brsh.alpha, 1);
	rotate_y(data, data->brsh.beta, 1);
	rotate_z(data, data->brsh.gamma, 1);
}

static void	rotate_x(t_data *data, double alpha, int n)
{
	int	p_y;

	if (n == 0)
	{
		p_y = data->brsh.y0;
		data->brsh.y0 = p_y * cos(alpha) + data->brsh.z0 * sin(alpha);
		data->brsh.z0 = -p_y * sin(alpha) + data->brsh.z0 * cos(alpha);
	}
	else
	{
		p_y = data->brsh.y1;
		data->brsh.y1 = p_y * cos(alpha) + data->brsh.z1 * sin(alpha);
		data->brsh.z1 = -p_y * sin(alpha) + data->brsh.z1 * cos(alpha);
	}
}

static void	rotate_y(t_data *data, double beta, int n)
{
	int	p_x;

	if (n == 0)
	{
		p_x = data->brsh.x0;
		data->brsh.x0 = p_x * cos(beta) + data->brsh.z0 * sin(beta);
		data->brsh.z0 = -p_x * sin(beta) + data->brsh.z0 * cos(beta);
	}
	else
	{
		p_x = data->brsh.x1;
		data->brsh.x1 = p_x * cos(beta) + data->brsh.z1 * sin(beta);
		data->brsh.z1 = -p_x * sin(beta) + data->brsh.z1 * cos(beta);
	}
}

static void	rotate_z(t_data *data, double gamma, int n)
{
	int	p_x;
	int	p_y;

	if (n == 0)
	{
		p_x = data->brsh.x0;
		p_y = data->brsh.y0;
		data->brsh.x0 = p_x * cos(gamma) - p_y * sin(gamma);
		data->brsh.y0 = p_x * sin(gamma) + p_y * cos(gamma);
	}
	else
	{
		p_x = data->brsh.x1;
		p_y = data->brsh.y1;
		data->brsh.x1 = p_x * cos(gamma) - p_y * sin(gamma);
		data->brsh.y1 = p_x * sin(gamma) + p_y * cos(gamma);
	}
}
