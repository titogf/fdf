/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:06:33 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/14 16:03:58 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_degrees(int key, t_data *data);

void	ft_key_proyection(int key, t_data *data)
{
	if (key == 35)
	{
		data->proyection = 2;
		data->brsh.alpha = 0;
		data->brsh.beta = 0;
		data->brsh.gamma = 0;
		ft_black(data);
		ft_draw_x(data, 2);
	}
	if (key == 34)
	{
		data->c = 2;
		data->proyection = ISO;
		if (data->brsh.alpha != 0 || data->brsh.beta != 0)
			data->c = 1;
		if (data->brsh.gamma != 0)
			data->c = 1;
		ft_black(data);
		ft_draw_x(data, data->c);
		data->c = 2;
	}
}

void	ft_key_zoom(int key, t_data *data)
{
	int	n;
	int	c;

	n = 10;
	c = 4;
	if (data->proyection == ISO)
		n = 4;
	if (data->columns > 200)
		n = 200;
	if (data->columns > 200)
		c = 200;
	if (key == 30 || key == 69)
	{
		data->space += 1;
		data->posx -= n;
		data->posy -= c;
	}
	if (key == 44 || key == 78)
	{
		data->space -= 1;
		data->posx += n;
		data->posy += c;
	}
	ft_black(data);
	ft_draw_x(data, data->c);
}

void	ft_key_move(int key, t_data *data)
{
	int	n;

	n = 4;
	if (data->columns > 200)
		n = 10;
	if (key == 123 || key == 0)
		data->posx -= n;
	if (key == 124 || key == 2)
		data->posx += n;
	if (key == 125 || key == 1)
		data->posy += n;
	if (key == 126 || key == 13)
		data->posy -= n;
	ft_black(data);
	ft_draw_x(data, data->c);
}

void	ft_key_degrees(int key, t_data *data)
{
	if (key == 18 || key == 83)
		data->brsh.alpha += 0.05;
	if (key == 19 || key == 84)
		data->brsh.alpha -= 0.05;
	if (key == 23 || key == 87)
		data->brsh.beta += 0.05;
	ft_black(data);
	ft_degrees(key, data);
	ft_draw_x(data, data->c);
}

static void	ft_degrees(int key, t_data *data)
{
	if (key == 22 || key == 88)
		data->brsh.beta -= 0.05;
	if (key == 25 || key == 92)
		data->brsh.gamma += 0.05;
	if (key == 29 || key == 82)
		data->brsh.gamma -= 0.05;
}
