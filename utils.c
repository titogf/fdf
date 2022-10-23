/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:51:01 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/20 15:53:35 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_return_nb(char *str, int i, int base);

void	ft_legend(t_data *data, int n)
{
	char	*c;

	if (n == 1)
	{
		data->div2 = 1;
		ft_len1(data);
	}
	else
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
 	c = "Press ESC to close the program";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 840, 15, 666, c);
 	c = "Press + or - to change the zoom";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 840, 40, 666, c);
 	c = "Press the arrows to move the map";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 840, 65, 666, c);
 	c = "Press P to change to plant view";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 840, 90, 666, c);
 	c = "Press I to change to isometric view";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 840, 115, 666, c);
}

void	ft_putpixel(t_data *data, int mx, int my)
{
	double	x;
	double	y;

	x = data->brsh.x0;
	y = data->brsh.y0;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color[my][mx]);
}

void	ft_putfinish(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	exit(1);
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
