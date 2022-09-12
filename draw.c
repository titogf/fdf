/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:31 by gfernand          #+#    #+#             */
/*   Updated: 2022/09/12 14:13:11 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//void	ft_line_to_pixel(t_data *data);
static void	ft_first_pixel(t_data *data);

static void	ft_first_pixel(t_data *data)
{
	printf("columnassss %i", data->columns);
	if (data->columns < 30)
		data->location = 20;
	if (data->columns > 29 && data->columns < 60)
		data->location = 14;
	if (data->columns > 59 && data->columns < 80)
		data->location = 8;
	if (data->columns > 79 && data->columns < 120)
		data->location = 6;
	if (data->columns > 119 && data->columns < 160)
		data->location = 4;
	if (data->columns > 159 && data->columns < 260)
		data->location = 3;
	if (data->columns > 259)
		data->location = 1;
}

void	ft_draw(t_data *data)
{
	int	lenx;
	int	leny;
	int	x;
	int	y;

	ft_first_pixel(data);
	data->posx = WIDE / 2 - data->columns * data->location / 2;
	data->posy = HEIGHT / 2 - data->rows * data->location / 2;
	y = 0;
	while (data->height[y] && y < data->rows)
	{
		x = 0;
		//printf("\n†\n");
		while ((data->height[y][x] || data->height[y][x] == 0) && x < data->columns)
		{
			//printf("->%i", data->height[y][x]);
			lenx = data->posx + x * data->location;
			leny = data->posy + y * data->location - data->height[y][x];
			if (data->color[y][x] == -1)
				data->color[y][x] = 16777215;
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, lenx, leny, data->color[y][x]);
			x++;
		}
		y++;
	}
}

/*void	ft_line_to_pixel(t_data *data, int lenx, int leny);
{
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, lenx, leny, data->color[y][x]);
}*/

