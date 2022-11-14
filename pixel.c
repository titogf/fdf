/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:43:36 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/14 16:24:08 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_data *data, int x, int y, int color);

void	ft_putpixel(t_data *data, int color)
{
	double	x;
	double	y;

	x = data->brsh.x0;
	y = data->brsh.y0;
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits,
			&data->img.line, &data->img.end);
	if (x > 0 && x < WIDE && y > 0 && y < HEIGHT - 90)
	{
		if (x < MAX && x > MIN && y < MAX && y > MIN)
			put_pixel(data, x, y, color);
	}
}

static void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = data->img.bits - 8;
	pixel = data->img.addr + (y * data->img.line + x * (data->img.bits / 8));
	while (i >= 0)
	{
		if (data->img.end != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->img.bits - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	ft_black(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDE)
			put_pixel(data, x, y, 0);
	}
}
