/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:39:23 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/09 16:59:58 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int	fd;
	void	*mlx_ptr;
	void	*win_ptr;

	if (argc != 2)
		ft_putfinish("WRONG PARAMETERS\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_putfinish("WRONG MAP");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 600, 300, "window");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		ft_putfinish("WRONG WINDOW\n");
	}
	while (1)
		;
	mlx_destroy_window(mlx_ptr, win_ptr);
	free(mlx_ptr);
	return (0);
}
