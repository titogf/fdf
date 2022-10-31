/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:55:04 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/31 15:18:27 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_data *data, double alpha)
{
	int	y;
	int	z;

	y = data->brsh.y0 * cos(alpha) + data->height[my][mx] * sin(alpha);
	z = -data->brsh.y0 * sin(alpha) + data->height[my][mx] * cos(alpha);
}

void	rotate_y(t_data *data, double beta)
{
	int	x;
	int	z;

	x = data->brsh.x0 * cos(beta) + data->height[my][mx] * sin(beta);
	z = -data->brsh.x0 * sin(beta) + data->height[my][mx] * cos(beta);
}

void	rotate_z(t_data *data, double gamma)
{
	int	x;
	int	y;

	x = data->brsh.x0 * cos(gamma) - data->brsh.y0 * sin(gamma);
	y = data->brsh.x0 * sin(gamma) + data->brsh.y0 * cos(gamma);
}
