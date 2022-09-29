/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:09:16 by gfernand          #+#    #+#             */
/*   Updated: 2022/09/29 13:10:28 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	ft_bresenham(t_data *data, int x, int y)
{
	int	dx;
	int	dy;
	int	p;

	dx = data->brsh.x1 - data->brsh.x0;
	dy = data->brsh.y1 - data->brsh.y0;
	p = 2 * dy - dx;
	while (data->brsh.x0 < data->brsh.x1)
	{
		if (p >= 0)
		{
			ft_putpixel(data, x, y);
			data->brsh.y0 = data->brsh.y0 + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			ft_putpixel(data, x, y);
			p = p + 2 * dy;
		}
		data->brsh.x0 = data->brsh.x0 + 1;
	}
}*/
