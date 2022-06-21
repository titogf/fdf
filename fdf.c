/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:39:23 by gfernand          #+#    #+#             */
/*   Updated: 2022/06/21 16:38:04 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	checkleaks(void)
{
	system("leaks fdf");
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	atexit(checkleaks);
	if (ac != 2)
		ft_putfinish("WRONG PARAMETERS\n");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_putfinish("WRONG MAP\n");
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDE, HEIGHT, "FDF");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		ft_putfinish("WRONG WINDOW\n");
	}
	ft_prueba(&data);
	ft_malloc(&data, fd);
	ft_get_map(&data, av[1], fd);
	ft_draw(&data);
	ft_window(&data);
	return (0);
}
