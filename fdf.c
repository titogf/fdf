/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:39:23 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/14 16:08:52 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_wrong(int ac, char *av);
static void	ft_map(char *av);

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	ft_wrong(ac, av[1]);
	fd = open(av[1], O_RDONLY);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDE, HEIGHT, "FDF");
	if (data.win == NULL)
	{
		free(data.win);
		ft_putfinish("WRONG WINDOW\n");
	}
	data.img.img = mlx_new_image(data.mlx, WIDE, HEIGHT);
	ft_malloc(&data, av[1], fd);
	ft_draw_x(&data, 1);
	ft_window(&data);
	return (0);
}

static void	ft_wrong(int ac, char *av)
{
	int	fd;
	int	fd_dir;

	if (ac != 2)
		ft_putfinish("WRONG PARAMETERS\n");
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_putfinish("WRONG MAP\n");
	else
	{
		fd_dir = open(av, O_DIRECTORY);
		if (fd_dir != -1)
			ft_putfinish("PATH IS A DIRECTORY\n");
		close(fd_dir);
	}
	close (fd);
	ft_map(av);
}

static void	ft_map(char *av)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (av[i])
		i++;
	if (av[--i] == 'f')
		c = 1;
	if (av[--i] == 'd')
		c = 1;
	if (av[--i] == 'f')
		c = 1;
	if (av[--i] == '.')
		c = 1;
	if (c == 0)
		ft_putfinish("WRONG MAP\n");
}
