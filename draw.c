/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:31 by gfernand          #+#    #+#             */
/*   Updated: 2022/06/21 15:24:48 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_data *data)
{
	int	lenx;
	int	leny;
	int	x;
	int	y;

	lenx = data->columns / 2;
	leny = data->rows / 2;
	lenx = WIDE / 2 - lenx;
	leny = HEIGHT / 2 - leny;
	printf("%i\n", lenx);
	y = 0;
	while (data->height[y] && y < data->rows)
	{
		x = 0;
		printf("\n†\n");
		while ((data->height[y][x] || data->height[y][x] == 0) && x < data->columns)
		{
			printf("->%i", data->height[y][x]);
			if (data->color[y][x] == -1)
				data->color[y][x] = 16777215;
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, lenx - x, leny - y, data->color[y][x]);
			x++;
		}
		y++;
	}
}
