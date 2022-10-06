/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:56:40 by gfernand          #+#    #+#             */
/*   Updated: 2022/09/29 16:02:08 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_len2(t_data *data, int space);
static int	ft_len3(t_data *data, int space, int x, int y);

void	ft_len1(t_data *data)
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

	if (data->location != 1)
	{
		y = -1;
		while (++y < data->rows)
		{
			x = -1;
			while (++x < data->columns)
			{
				if (ft_len3(data, space, x, y) == 1)
					return ;
			}
		}
	}
}

static int	ft_len3(t_data *data, int space, int x, int y)
{
	if (data->posx + x * space <= 0 || data->posx + x * space >= WIDE)
	{
		data->div2++;
		ft_len1(data);
		return (1);
	}
	if (data->posy + y * space - data->height[y][x] * space <= 0)
	{
		data->div2++;
		ft_len1(data);
		return (1);
	}
	if (data->posy + y * space - (data->height[y][x] * space) >= HEIGHT)
	{
		data->div2++;
		ft_len1(data);
		return (1);
	}
	return (0);
}