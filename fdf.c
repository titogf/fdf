/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:39:23 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/30 17:30:01 by gfernand         ###   ########.fr       */
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
	char	**str;
	t_data	data;

	//atexit(checkleaks);
	fd = open(av[1], O_RDONLY);
	if (ac != 2 || fd < 0)
		ft_putfinish("WRONG PARAMETERS\n");
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDE, HEIGHT, "FDF");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		ft_putfinish("WRONG WINDOW\n");
	}
	str = ft_get_map(data, av[1], fd);
	mlx_hook(data.win_ptr, 02, 1L << 0, &keyb, &data);
	mlx_hook(data.win_ptr, 17, 1L < 17, &exkey, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
	return (0);
}
