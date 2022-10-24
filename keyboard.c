/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:37:44 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/24 16:32:39 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	keyb(int key, t_data *data);
static int	exkey(t_data *data);

static int	exkey(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	exit(1);
}

static int	keyb(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(1);
	}
	if (key == 35)
	{
		data->c = 5;
		ft_draw_x(data, data->c);
	}
	if (key == 34)
	{
		data->c = 2;
		if (data->brsh.cs != cos(0.524) || data->brsh.sn != sin(0.524))
			data->c = 1;
		ft_draw_x(data, data->c);
		data->c = 2;
	}
	ft_key_degrees(key, data);
	ft_key_zoom(key, data);
	ft_key_move(key, data);
	return (0);
}

void	ft_window(t_data *data)
{
	data->c = 2;
	mlx_hook(data->win_ptr, 02, 1L << 0, &keyb, data);
	mlx_hook(data->win_ptr, 17, 1L < 17, &exkey, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
}
