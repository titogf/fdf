/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:37:44 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/14 14:46:02 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	keyb(int key, t_data *data);
static int	exkey(t_data *data);

static int	exkey(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	exit(1);
}

static int	keyb(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		exit(1);
	}
	ft_key_proyection(key, data);
	ft_key_degrees(key, data);
	ft_key_zoom(key, data);
	ft_key_move(key, data);
	return (0);
}

void	ft_window(t_data *data)
{
	data->c = 2;
	mlx_hook(data->win, 02, 1L << 0, &keyb, data);
	mlx_hook(data->win, 17, 1L < 17, &exkey, data);
	mlx_loop(data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
}
