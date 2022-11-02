/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:55:04 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/02 19:42:35 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(int y, int z, double alpha);
static void	rotate_y(int x, int z, double beta);
static void	rotate_z(int x, int y, double gamma);

void	ft_rotate(t_data *data)
{
	rotate_x(data->brsh.y0, data->brsh.z0, data->brsh.alpha);
	rotate_y(data->brsh.x0, data->brsh.z0, data->brsh.beta);
	rotate_z(data->brsh.x0, data->brsh.y0, data->brsh.gamma);
	rotate_x(data->brsh.y1, data->brsh.z1, data->brsh.alpha);
	rotate_y(data->brsh.x1, data->brsh.z1, data->brsh.beta);
	rotate_z(data->brsh.x1, data->brsh.y1, data->brsh.gamma);
}

static void	rotate_x(int y, int z, double alpha)
{
	int	p_y;

	p_y = y;
	y = p_y * cos(alpha) + z * sin(alpha);
	z = -p_y * sin(alpha) + z * cos(alpha);
}

static void	rotate_y(int x, int z, double beta)
{
	int	p_x;

	p_x = x;
	x = p_x * cos(beta) + z * sin(beta);
	z = -p_x * sin(beta) + z * cos(beta);
}

static void	rotate_z(int x, int y, double gamma)
{
	int	p_x;
	int	p_y;

	p_x = x;
	p_y = y;
	x = p_x * cos(gamma) - p_y * sin(gamma);
	y = p_x * sin(gamma) + p_y * cos(gamma);
}
