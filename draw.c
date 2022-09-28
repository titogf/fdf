/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:31 by gfernand          #+#    #+#             */
/*   Updated: 2022/09/19 19:01:37 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_len_map(t_data *data);
//static void	ft_bresenham(t_data *data, int x, int y);

static void	ft_len_map(t_data *data)
{
	if (data->columns < 30)
		data->location = 20;
	if (data->columns > 29 && data->columns < 60)
		data->location = 14;
	if (data->columns > 59 && data->columns < 80)
		data->location = 6;
	if (data->columns > 79 && data->columns < 120)
		data->location = 4;
	if (data->columns > 119 && data->columns < 160)
		data->location = 3;
	if (data->columns > 159 && data->columns < 260)
		data->location = 2;
	if (data->columns > 259)
		data->location = 1;
}

void	ft_draw(t_data *data)
{
	int	x;
	int	y;
	int	space;

	ft_len_map(data);
	space = data->location;
	data->posx = WIDE / 2 - data->columns * space / 2;
	data->posy = HEIGHT / 2 - data->rows * space / 2;
	y = 0;
	while (data->height[y] && y < data->rows)
	{
		x = 0;
		while (x <= data->columns)
		{
			data->brsh.x0 = x * space;
			data->brsh.y0 = y * space  - data->height[y][x] * space;
			ft_putpixel(data, x, y);
			/*data->brsh.x1 = data->posx + (x + 1) * data->location;
			data->brsh.y1 = data->brsh.y0 - data->height[y][x + 1];
			ft_bresenham(data, x, y);*/
			x++;
		}
		y++;
	}
}

void	ft_putpixel(t_data *data, int x, int y)
{
	double	x0;
	double	y0;
	double	cs;
	double	sen;

	cs = cos(0.523599);
	sen = sin(0.523599);
	x0 = (data->brsh.x0 - data->brsh.y0) * cs;
	y0 = -data->height[y][x] + (data->brsh.y0 + data->brsh.x0) * sen;
	x0 = x0 + data->posx;
	y0 = y0 + data->posy;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, data->color[y][x]);
}

/*static void	ft_bresenham(t_data *data, int x, int y)
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
