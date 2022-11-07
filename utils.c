/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:51:01 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/07 12:26:05 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_return_nb(char *str, int i, int base);
static void	ft_legend_2(t_data *data);

void	ft_legend(t_data *data, int n)
{
	char	*c;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (n == 1)
	{
		data->brsh.alpha = 0;
		data->brsh.beta = 0;
		data->brsh.gamma = 0;
		data->proyection = ISO;
		data->div2 = 1;
		ft_len1(data);
	}
	c = "->To close the program";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 5, BLUE, c);
	c = "-Press ESC";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 40, 25, B2, c);
	c = "-Press the red cross";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 40, 45, B2, c);
	c = "->To move the map";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 275, 5, BLUE, c);
	ft_legend_2(data);
}

static void	ft_legend_2(t_data *data)
{
	char	*c;

	c = "-Press the rows to displace";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 310, 25, B2, c);
	c = "-Press +/- to change the zoom";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 310, 45, B2, c);
	c = "->To change the view:";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 635, 5, BLUE, c);
	c = "-Press P to plant view";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 670, 25, B2, c);
	c = "-Press I to isometric view";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 670, 45, B2, c);
	c = "->To change degrees";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 955, 5, BLUE, c);
	c = "-Press 1/2 X degrees";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 990, 25, B2, c);
	c = "-Press 5/6 Y degrees";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 990, 45, B2, c);
	c = "-Press 9/0 Z degrees";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 990, 65, B2, c);
}

void	ft_putpixel(t_data *data, int color)
{
	double	x;
	double	y;

	x = data->brsh.x0;
	y = data->brsh.y0;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
}

int	ft_atoi_base(char *str, int base)
{
	int	i;
	int	nb;
	int	sig;

	if (!str || !str[0])
		return (-1);
	i = 0;
	nb = 0;
	sig = 1;
	if (str[0] == '0' && str[1] == 'x')
		i = 2;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i])
	{
		nb = nb * base;
		nb = nb + ft_return_nb(str, i, base);
		i++;
	}
	return (nb * sig);
}

static int	ft_return_nb(char *str, int i, int base)
{
	char	*hex1;
	char	*hex2;
	int		j;

	j = 0;
	hex1 = "0123456789abcdef";
	hex2 = "0123456789ABCDEF";
	while (j <= base)
	{
		if (str[i] == hex1[j] || str[i] == hex2[j])
			return (j);
		j++;
	}
	return (-1);
}
