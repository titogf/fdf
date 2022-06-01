/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:42 by gfernand          #+#    #+#             */
/*   Updated: 2022/06/01 14:22:42 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_malloc(t_data *data, int fd)
{
	int		i;
	int		row;
	int		colum;

	ft_matrizlen(data, fd);
	row = data->rows;
	colum = data->columns;
	data->height = malloc(sizeof(int *) * row);
	data->color = malloc(sizeof(int *) * row);
	i = -1;
	while (++i < row)
	{
		data->height[i] = malloc(sizeof(int *) * colum);
		data->color[i] = malloc(sizeof(int *) * colum);
	}
	return (0);
}

char	**ft_get_map(t_data *data, char *av, int fd)
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
		int o = 0;
		while(str[o])
		{
			printf("SI ---> %s\n", str[o]);
			o++;
		}
		while (count-- > 0)
		{
			s = ft_split(str[count], ',');
			o = 0;
			while (s[o])
			{
				printf("NO = %s\n", s[o]);
				o++;
			}
			ft_map_point(data, s, i, count);
			ft_splitfree(s);
		}
		ft_splitfree(str);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (s);
}

int	ft_map_point(t_data *data, char **s, int i, int count)
{
	//printf("LA S %s\n", s[0]);
	//printf("---> %i\n", ft_atoi_base(s[0], 10));
	data->height[i][count] = ft_atoi_base(s[0], 10);
	data->color[i][count] = ft_atoi_base(s[1], 16);
	//printf("ALTURA = %i\n", data->height[i][count]);
	//printf("COLOR = %i\n", data->color[i][count]);
	if (count == 0)
		i++;
	return (0);
}

int	ft_matrizlen(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line != NULL)
	{
		data->columns = ft_count(line, ' ');
		data->rows = 0;
		while (line != NULL)
		{
			//printf("%s\n", line);
			data->rows++;
			free(line);
			line = get_next_line(fd);
		}
	}
	close(fd);
	return (0);
}
