/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:25:31 by gfernand          #+#    #+#             */
/*   Updated: 2022/09/29 14:12:12 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_len_map(t_data *data);
static void	ft_len2(t_data *data, int space);

void	ft_draw(t_data *data)
{
	int	x;
	int	y;
	int	space;

	data->div2 = 1;
	ft_len_map(data);
	space = data->location;
	y = 0;
	while (data->height[y] && y < data->rows)
	{
		x = 0;
		while (x <= data->columns)
		{
			data->brsh.x0 = x * space;
			data->brsh.y0 = y * space  - data->height[y][x] * space;
			ft_putpixel(data, x, y);
			/*data->brsh.x1 = (x + 1) * space;
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

static void	ft_len_map(t_data *data)
{
	int	size;
	int	space;

	size = data->columns * data->div2;
	if (size < 20)
		data->location = 20;
	if (size > 19 && size < 30)
		data->location = 14;
	if (size > 29 && size < 60)
		data->location = 7;
	if (size > 59 && size < 80)
		data->location = 4;
	if (size > 79 && size < 110)
		data->location = 3;
	if (size > 109 && size < 160)
		data->location = 2;
	if (size > 159)
		data->location = 1;
	space = data->location;
	data->posx = WIDE / 2 - data->columns / 2 * space / 2;
	data->posy = HEIGHT / 2 - data->rows / 2 * space;
	ft_len2(data, space);
}

static void	ft_len2(t_data *data, int space)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->rows)
	{
		x = -1;
		while (++x < data->columns)
		{
			if (data->posx + x * space <= 0 || data->posx + x * space >= WIDE)
			{
				data->div2++;
				ft_len_map(data);
				return ;
			}
			if (data->posy + y * space - data->height[y][x] * space <= 0)
			{
				data->div2++;
				ft_len_map(data);
				return ;
			}
			if (data->posy + y * space - (data->height[y][x] * space) >= HEIGHT)
			{
				data->div2++;
				ft_len_map(data);
				return ;
			}
		}
	}
}
