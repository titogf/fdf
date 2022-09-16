/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:31 by gfernand          #+#    #+#             */
/*   Updated: 2022/09/15 16:38:23 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_first_pixel(t_data *data);
static void	ft_bresenham(t_data *data, int x, int y);

static void	ft_first_pixel(t_data *data)
{
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
	//int	lenx;
	//int	leny;
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
			data->brsh.x0 = data->posx + x * data->location;//lenx
			data->brsh.y0 = data->posy + y * data->location - data->height[y][x];//leny
			if (data->color[y][x] == -1)
				data->color[y][x] = 16777215;
			//data->brsh.x0 = lenx;
			//data->brsh.y0 = leny;
			ft_putpixel(data, x, y);//mlx_pixel_put(data->mlx_ptr, data->win_ptr, lenx, leny, data->color[y][x]);//hacer una funcion de put
			data->brsh.x1 = data->posx + (x + 1) * data->location;
			data->brsh.y1 = data->brsh.y0;
			ft_putpixel(data, x, y);//mlx_pixel_put(data->mlx_ptr, data->win_ptr, lenx, leny, data->color[y][x]);//hacer una funcion de put
			ft_bresenham(data, x, y);
			x++;
		}
		y++;
	}
}

static void	ft_bresenham(t_data *data, int x, int y)
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
			//mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, data->color[y][x]);
			data->brsh.y0 = data->brsh.y0 + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			ft_putpixel(data, x, y);
			//mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, data->color[y][x]);
			p = p + 2 * dy;
		}
		data->brsh.x0 = data->brsh.x0 + 1;
	}

}
