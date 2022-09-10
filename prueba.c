/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:36:16 by gfernand          #+#    #+#             */
/*   Updated: 2022/06/21 16:46:44 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_prueba(t_data *data)
{
	int	x;
	int	i;

	i = 0;
	x = WIDE / 2;
	while (i <= HEIGHT)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, i, 16777215);
		i++;
	}
	i = HEIGHT / 2;
	x = 0;
	while (x <= WIDE)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, i, 16777215);
		x++;
	}

	/*x = data->color[1][1];
	x = 300;
	while (x <= 900)
	{
		i = 200;
		while (i <= 800)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, i, 16777215);
			i++;
		}
		x += 50;
	}
	i = 200;
	while (i <= 800)
	{	
		x = 300;
		while (x <= 900)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, i, 16777215);
			x++;
		}
		i += 50;
	}*/
}
