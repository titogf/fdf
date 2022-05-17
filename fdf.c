/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:39:23 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/17 18:11:25 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static char	**ft_get_map(int fd);
static int	ft_filas(int fd);
static int	ft_columnas(int fd);

void checkLeaks(void)
{
	system("leaks fdf");
}

int	main(int ac, char **av)
{
	int		fd;
	int		files;
	int		columns;
	char	**str;
	t_data	data;

	atexit(checkLeaks);
	if (ac != 2)
		ft_putfinish("WRONG PARAMETERS\n");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_putfinish("WRONG MAP");
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, HEIGHT, WIDE, "FDF");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		ft_putfinish("WRONG WINDOW\n");
	}
	str = ft_get_map(fd);
	free(str);
	close(fd);
	fd = open(av[1], O_RDONLY);
	columns = ft_columnas(fd);
	files = ft_filas(fd);
	mlx_hook(data.win_ptr, 02, 1L << 0, &keyb, &data);
	mlx_hook(data.win_ptr, 17, 1L < 17, &exkey, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
	return (0);
}

static char	**ft_get_map(int fd)
{
	char	*line;
	char	**str;
	char	**s;
	int		i;
	int		count;

	line = get_next_line(fd);
	while (line != NULL)
	{
		count = ft_count(line, ' ');
		str = ft_split(line, ' ');
		i = 0;
		while (count > 0)
		{
			s = ft_split(str[i], ',');
			count--;
			i++;
		}
		ft_splitfree(str, count);
		free(line);
		line = get_next_line(fd);
	}
	return (s);
}

static int	ft_filas(int fd)
{
	int		f;
	char	*line;

	line = get_next_line(fd);
	f = 0;
	while (line != NULL)
	{
		f++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	printf("ESTO ES LA F:%i", f);
	return (f);
}

static int	ft_columnas(int fd)
{
	int		c;
	char	*line;

	line = get_next_line(fd);
	c = ft_count(line, ' ');
	close(fd);
	free(line);
	printf("ESTO ES LA C:%i\n", c);
	return (c);
}
