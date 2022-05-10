/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:39:23 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/10 17:21:19 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int  ft_pixel(t_data *data);
static int  keyb(int key, t_data *data);

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	if (argc != 2)
		ft_putfinish("WRONG PARAMETERS\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_putfinish("WRONG MAP");
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 900, 600, "FDF");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		ft_putfinish("WRONG WINDOW\n");
	}
	mlx_loop_hook(data.mlx_ptr, &ft_pixel, &data);
	mlx_hook(data.win_ptr, 02, 1L<<0, &keyb, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
	return (0);
}

static int	ft_pixel(t_data *data)
{
	if (data->win_ptr)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, 450, 300, 0xFF0000);
	return (0);
}

static int	keyb(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(1);
	}
	return (0);
}
