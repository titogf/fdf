/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:49:42 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/19 18:28:52 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_get_map(t_data data, char *av, int fd)
{
	char	*line;
	char	**str;
	char	**s;
	int		count;

	line = get_next_line(fd);
	while (line != NULL)
	{
		count = ft_count(line, ' ') - 1;
		str = ft_split(line, ' ');
		while (count >= 0)
		{
			s = ft_split(str[count], ',');
			//ft_map_point(data, s, av, count);
			ft_splitfree(s);
			count--;
		}
		ft_splitfree(str);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (s);
}

int	**ft_map_point(t_data data, char **s, char *av, int	count)
{
	int		i;
	char	**s;

	i = 0;
	height = malloc(sizeof (char *) ft_rows(av) * ft_columns(av));
	color = malloc(sizeof (char *) ft_rows(av) * ft_columns(av));
	height[i][count] = ft_atoi(s[0]);
	if (ft_atoi(s[1]) == -1)
		color[i][count] = NULL;
	else
		color[i][count] = ft_atoi(s[1]);
	if (count == 0)
		i++;
}

int	ft_rows(char *av)
{
	int		f;
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	f = 0;
	while (line != NULL)
	{
		f++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (f);
}

int	ft_columns(char *av)
{
	int		c;
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	c = ft_count(line, ' ');
	close(fd);
	free(line);
	return (c);
}

