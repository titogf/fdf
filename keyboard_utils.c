/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:06:33 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/31 17:12:40 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_degrees(int key, t_data *data);

void	ft_key_zoom(int key, t_data *data)
{
	if (key == 30 || key == 69)
	{
		data->space += 1;
		ft_draw_x(data, data->c);
	}
	if (key == 44 || key == 78)
	{
		data->space -= 1;
		ft_draw_x(data, data->c);
	}
}

void	ft_key_move(int key, t_data *data)
{
	int	n;

	n = 4;
	if (data->columns > 200)
		n = 10;
	if (key == 123 || key == 0)
	{
		data->posx -= n;
		ft_draw_x(data, data->c);
	}
	if (key == 124 || key == 2)
	{
		data->posx += n;
		ft_draw_x(data, data->c);
	}
	if (key == 125 || key == 1)
	{
		data->posy += n;
		ft_draw_x(data, data->c);
	}
	if (key == 126 || key == 13)
	{
		data->posy -= n;
		ft_draw_x(data, data->c);
	}
}

void	ft_key_degrees(int key, t_data *data)
{
	if (key == 18)
	{
		data->brsh.alpha += 0.05;
		ft_draw_x(data, data->c);
	}
	if (key == 19)
	{
		data->brsh.alpha -= 0.05;
		ft_draw_x(data, data->c);
	}
	if (key == 20)
	{
		data->brsh.beta += 0.05;
		ft_draw_x(data, data->c);
	}
	ft_degrees(key, data);
}

static void	ft_degrees(int key, t_data *data)
{
	if (key == 21)
	{
		data->brsh.beta -= 0.05;
		ft_draw_x(data, data->c);
	}
	if (key == 23)
	{
		data->brsh.gamma += 0.05;
		ft_draw_x(data, data->c);
	}
	if (key == 22)
	{
		data->brsh.gamma -= 0.05;
		ft_draw_x(data, data->c);
	}
}
