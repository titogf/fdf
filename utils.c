/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:51:01 by gfernand          #+#    #+#             */
/*   Updated: 2022/06/01 15:07:13 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_return_nb(char *str, int i, int base);

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

void	ft_putpixel(t_data *data, int x, int y)
{
	double	x0;
	double	y0;
	double	cs;
	double	sen;

	cs = cos(0.523599);
	sen = sin(0.523599);
	x0 = (data->brsh.x0 - data->brsh.y0) * cs;
	y0 = -data->height[y][x] + (data->brsh.y0 + data->brsh.x0) * sen;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, data->color[y][x]);
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
