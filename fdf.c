/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:39:23 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/07 12:25:13 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_wrong(int ac, char *av);
static void	ft_putfinish(char *str);

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	fd = ft_wrong(ac, av[1]);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDE, HEIGHT, "FDF");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		ft_putfinish("WRONG WINDOW\n");
	}
	ft_malloc(&data, av[1], fd);
	ft_draw_x(&data, 1);
	ft_window(&data);
	return (0);
}

static int	ft_wrong(int ac, char *av)
{
	int	fd;

	if (ac != 2)
		ft_putfinish("WRONG PARAMETERS\n");
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_putfinish("WRONG MAP\n");
	return (fd);
}

static void	ft_putfinish(char *str)
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
