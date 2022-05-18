/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:14:03 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/18 13:09:35 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*get_next_line(int fd)
{
	static char	*s;
	char		*str;
	char		*line;
	int			i;
	char		*aux;

	if (BUFFER_SIZE < 1 || fd < 0 || fd >= 256)
		return (NULL);
	str = ft_stuff();
	if (!s)
		s = ft_stuff();
	i = ft_enter(s);
	if (i == -1 || s[i] != '\n')
	{
		aux = str;
		str = ft_read(str, fd);
		if (str == NULL)
			return (ft_free(aux, s));
	}
	line = ft_export_line(str, s);
	aux = s;
	s = ft_leftover(str, s);
	free(aux);
	return (line);
}

char	*ft_read(char *str, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*aux;
	int		length;

	length = BUFFER_SIZE;
	while (ft_enter(str) == -1 && length == BUFFER_SIZE)
	{
		length = read(fd, buff, BUFFER_SIZE);
		if (length < 0)
			return (NULL);
		buff[length] = '\0';
		if (length <= 0)
			break ;
		aux = ft_strjoin(str, buff, 0);
		free(str);
		str = aux;
	}
	return (str);
}

void	*ft_free(char *aux, char *s)
{
	free(aux);
	free(s);
	return (NULL);
}

char	*ft_export_line(char *str, char *s)
{
	char	*buff;
	char	*string;
	int		i;

	string = ft_strjoin(s, str, 0);
	i = 0;
	if (string == NULL)
		return (NULL);
	while (string[i] != '\n' && string[i])
		i++;
	if (string[i] == '\n')
		i++;
	buff = ft_substr(string, 0, i);
	if (!ft_strlen(buff))
	{
		free(buff);
		return (NULL);
	}
	free(string);
	return (buff);
}

char	*ft_leftover(char *str, char *s)
{
	char	*aux;
	int		i;

	aux = ft_strjoin(s, str, 0);
	free(str);
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (aux[i] && aux[i] != '\n')
		i++;
	if (aux[i] == '\n')
		i++;
	if (ft_strlen(aux) == 0)
	{
		free(aux);
		return (NULL);
	}
	s = ft_substr(aux, i, ft_strlen(aux) - i);
	free(aux);
	return (s);
}
