/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:37:44 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/24 12:56:18 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	keyb(int key, t_data *data);
static void	ft_key_zoom(int key, t_data *data);
static void	ft_key_move(int key, t_data *data);
static int	exkey(t_data *data);

void	ft_window(t_data *data)
{
	data->c = 2;
	mlx_hook(data->win_ptr, 02, 1L << 0, &keyb, data);
	mlx_hook(data->win_ptr, 17, 1L < 17, &exkey, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
}

static int	exkey(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	exit(1);
}

static int	keyb(int key, t_data *data)
{
	printf("%d\n", key);
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
		ft_draw_x(data, data->c);
	}
	ft_key_zoom(key, data);
	ft_key_move(key, data);
	return (0);
}

static void	ft_key_zoom(int key, t_data *data)
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

static void	ft_key_move(int key, t_data *data)
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
