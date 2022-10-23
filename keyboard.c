/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:37:44 by gfernand          #+#    #+#             */
/*   Updated: 2022/09/12 13:03:10 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	keyb(int key, t_data *data);
static void	ft_key_move(int key, t_data *data);
static int	exkey(t_data *data);

void	ft_window(t_data *data)
{
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
		ft_draw_x(data, 5);
	if (key == 34)
		ft_draw_x(data, 2);
	if (key == 30)
	{
		data->space += 1;
		ft_draw_x(data, 2);
	}
	if (key == 44)
	{
		data->space -= 1;
		ft_draw_x(data, 2);
	}
	ft_key_move(key, data);
	return (0);
}

static void	ft_key_move(int key, t_data *data)
{
	int	n;

	n = 4;
	if ( data->columns > 200)
		n = 10;
	if (key == 123 || key == 0)
	{
		data->posx -= n;
		ft_draw_x(data, 2);
	}
	if (key == 124 || key == 2)
	{
		data->posx += n;
		ft_draw_x(data, 2);
	}
	if (key == 125 || key == 1)
	{
		data->posy += n;
		ft_draw_x(data, 2);
	}
	if (key == 126 || key == 13)
	{
		data->posy -= n;
		ft_draw_x(data, 2);
	}
}
