/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:42 by gfernand          #+#    #+#             */
/*   Updated: 2022/06/01 15:32:25 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_malloc(t_data *data, int fd)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (line != NULL)
	{
		data->columns = ft_count(line, ' ');
		data->rows = 0;
		while (line != NULL)
		{
			printf("%s\n", line);
			data->rows++;
			free(line);
			line = get_next_line(fd);
		}
	}
	close(fd);
	data->height = malloc(sizeof(int *) * data->rows);
	data->color = malloc(sizeof(int *) * data->rows);
	i = -1;
	while (++i < data->rows)
	{
		data->height[i] = malloc(sizeof(int *) * data->columns);
		data->color[i] = malloc(sizeof(int *) * data->columns);
	}
}

void	ft_get_map(t_data *data, char *av, int fd)
{
	char	**str;
	char	**s;
	char	*line;
	int		i;
	int		count;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	i = -1;
	while (line != NULL && ++i >= 0)
	{
		count = ft_count(line, ' ');
		str = ft_split(line, ' ');
		while (count-- > 0)
		{
			s = ft_split(str[count], ',');
			data->height[i][count] = ft_atoi_base(s[0], 10);
			data->color[i][count] = ft_atoi_base(s[1], 16);
			ft_splitfree(s);
		}
		ft_splitfree(str);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
