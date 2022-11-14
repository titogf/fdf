/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:25:43 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/14 15:42:47 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_legend_2(t_data *data);

void	ft_menu(t_data *data)
{
	char	*c;

	c = "->To close the program";
	mlx_string_put(data->mlx, data->win, 5, 5, BLUE, c);
	c = "-Press ESC";
	mlx_string_put(data->mlx, data->win, 40, 25, B2, c);
	c = "-Press the red cross";
	mlx_string_put(data->mlx, data->win, 40, 45, B2, c);
	c = "->To move the map";
	mlx_string_put(data->mlx, data->win, 275, 5, BLUE, c);
	ft_legend_2(data);
}

static void	ft_legend_2(t_data *data)
{
	char	*c;

	c = "-Press the rows to displace";
	mlx_string_put(data->mlx, data->win, 310, 25, B2, c);
	c = "-Press +/- to change the zoom";
	mlx_string_put(data->mlx, data->win, 310, 45, B2, c);
	c = "->To change the view:";
	mlx_string_put(data->mlx, data->win, 635, 5, BLUE, c);
	c = "-Press P to plant view";
	mlx_string_put(data->mlx, data->win, 670, 25, B2, c);
	c = "-Press I to isometric view";
	mlx_string_put(data->mlx, data->win, 670, 45, B2, c);
	c = "->To change degrees";
	mlx_string_put(data->mlx, data->win, 955, 5, BLUE, c);
	c = "-Press 1/2 X degrees";
	mlx_string_put(data->mlx, data->win, 990, 25, B2, c);
	c = "-Press 5/6 Y degrees";
	mlx_string_put(data->mlx, data->win, 990, 45, B2, c);
	c = "-Press 9/0 Z degrees";
	mlx_string_put(data->mlx, data->win, 990, 65, B2, c);
}
