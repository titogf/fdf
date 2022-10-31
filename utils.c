/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:51:01 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/31 14:34:36 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_return_nb(char *str, int i, int base);
static void	ft_degrees(t_data *data);

void	ft_legend(t_data *data, int n)
{
	char	*c;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (n == 1)
	{
		data->brsh.cs = 0.524;
		data->brsh.sn = 0.524;
		data->proyection = ISO;
		data->div2 = 1;
		ft_len1(data);
	}
	c = "Press ESC to close the program";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 5, 666, c);
	c = "Press + or - to change the zoom";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 25, 666, c);
	c = "Press the arrows to move the map";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 45, 666, c);
	c = "Press P to change to plant view";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 420, 5, 666, c);
	c = "Press I to change to isometric view";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 420, 25, 666, c);
	ft_degrees(data);
}

static void	ft_degrees(t_data *data)
{
	char	*c;

	c = "Press 1/2 to change X degrees";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 900, 5, 666, c);
	c = "Press 3/4 to change Y degrees";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 900, 25, 666, c);
	c = "Press 5/6 to change Z degrees";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 900, 45, 666, c);
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
